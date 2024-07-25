#if __cplusplus <= 199711L
  #error This library needs at least a C++11 compliant compiler
#endif


#ifndef JHUfunctions_H
#define JHUfunctions_H

#include <cmath>
#include <vector>
#include <math.h>


#include "TLorentzVector.h"
#include "ROOT/RVec.hxx"
#include "edm4hep/ReconstructedParticleData.h"
#include "edm4hep/MCParticleData.h"
#include "edm4hep/ParticleIDData.h"
#include "ReconstructedParticle2MC.h"
#include "/eos/user/n/nipinto/FCCAnalyzer/JHUGenerator.v7.5.4/JHUGenMELA/MELA/interface/TCouplings.hh" 
#include "/eos/user/n/nipinto/FCCAnalyzer/JHUGenerator.v7.5.4/JHUGenMELA/MELA/interface/Mela.h"


// Mela m = Mela(13, 125, TVar::DEBUG_MECHECK); 

Mela m = Mela(13, 125); 

map<string, double*> m_map; 

map<string, std::pair<float, float> > in_map; 

namespace FCCAnalyses { namespace JHUfunctions {

void build_map(pair<string, pair<float, float> > input){
    in_map[input.first] = input.second; 
}

void set_m_map(){
   m_map["ghz1"] = m.selfDHzzcoupl[0][0];
   m_map["ghz2"] = m.selfDHzzcoupl[0][1]; 
   m_map["ghz3"] = m.selfDHzzcoupl[0][2]; 
   m_map["ghz4"] = m.selfDHzzcoupl[0][3];

   m_map["ghzgs2"] = m.selfDHzzcoupl[0][4]; 
   m_map["ghzgs3"] = m.selfDHzzcoupl[0][5]; 
   m_map["ghzgs4"] = m.selfDHzzcoupl[0][6];
   m_map["ghgsgs2"] = m.selfDHzzcoupl[0][7]; 
   m_map["ghgsgs3"] = m.selfDHzzcoupl[0][8]; 
   m_map["ghgsgs4"] = m.selfDHzzcoupl[0][9]; 
}

Vec_tlv VecSum(Vec_tlv Vec1, Vec_tlv Vec2){
    Vec_tlv OutVec = Vec1+Vec2; 
    return OutVec; 
}


Vec_i gen_list(Vec_i mcin, Vec_mc in) {
   // mcin = index of a MC particle in the Particle block
   // in = the Particle collection
   // ind = the block with the indices for the daughters, Particle#1.index
   // returns a vector with the indices (in the Particle block) of the daughters of the particle i
   Vec_i result;
   for (size_t i = 0; i < mcin.size(); ++i) {
           cout << "This is the idx of particle @: "<< i << mcin[i] << endl; 
           cout << in[mcin[i]].PDG << endl;
            result.push_back(in[mcin[i]].PDG);
            }
   return result;
}



Vec_i get_gen_daus(int mcin, Vec_mc in, Vec_i ind) {
   // mcin = index of a mother. 
   // in = the Particle collection
   // ind = the block with the indices for the daughters, Particle#1.index
   //Returns the indices of initial the e+ e- daughters in the event, sorted in the order of (fermion-, fermion+, Higgs). 

   Vec_i result;
   Vec_i tempPDG;
   Vec_i tempIdx; 
        for (size_t j = 0; j < MCParticle::get_list_of_particles_from_decay(mcin,in,ind).size(); ++j) {
           //cout << in[MCParticle::get_list_of_particles_from_decay(mcin[i],in,ind)[j]].PDG << endl;
            tempPDG.push_back(in[MCParticle::get_list_of_particles_from_decay(mcin, in, ind)[j]].PDG);
            tempIdx.push_back(MCParticle::get_list_of_particles_from_decay(mcin, in, ind)[j]);
            //    cout << in[MCParticle::get_list_of_particles_from_decay(mcin[i], in, ind)[j]].PDG << endl; 
            }
  std::vector<std::pair<int, int>> paired_array; 
  for (size_t i = 0; i < tempPDG.size(); ++i){
    paired_array.push_back(make_pair(tempPDG[i], tempIdx[i])); 
  }
    
    sort(paired_array.begin(), paired_array.end()); 
    for (const auto& pair : paired_array) {
    result.push_back(pair.second);
    }
    //cout << paired_array << endl; 
    //cout << result << endl; 
    return result;

}


// Vec_tlv get_best_jet_pair(float DesiredMass, Vec_tlv Jets){
//     // Returns a vector holding one TLV best matched to the desired mass 
//     Vec_tlv result; 
//     float MassDiff;
//     float MassDiffOld = 9999999999.9; 
//     std::pair<int, int> GoodJets; 
//     for(size_t i = 0; i < Jets.size(); ++i){
//         for(size_t j = 1; j < Jets.size(); ++j){
//             if (j == i){
//                 continue; 
//             }
//             float Mij = (Jets[i] + Jets[j]).M(); 
//             MassDiff = pow((Mij - DesiredMass), 2);
//            // cout << "This is MassDiff: " << MassDiff << endl;  
//             if (MassDiff < MassDiffOld){
//                 GoodJets.first = i; 
//                 GoodJets.second = j; 
//                 MassDiffOld = MassDiff; 
//             }
//         }

//     }
//     // cout << "This is first index: " << GoodJets.first << endl; 
//     // cout << "This is second index: " << GoodJets.second << endl; 
//     result.push_back(Jets[GoodJets.first] + Jets[GoodJets.second]); 
//     return result; 
// }


// Vec_tlv get_best_jet_pair(float DesiredMass, float DesiredMRec, float ecm, Vec_tlv Jets){
//     // Returns a vector holding, in the first entry, a TLV best matched to the desired mass and making the recoil mass in the event closest to a specified value. 
//     // In the second entry, the four momentum of the recoil in the event is returned. 
//     //Entries 3 and 4 are the individual best jets. 
//     Vec_tlv result; 
//     float MassDiff;
//     float MRecDiff;
//     float Score;  
//     float MRec = 9999999999.9; 
//     float ScoreOld = 9999999999.9; 

//     float chi_squared_frac = 0.4; 
//     std::pair<int, int> GoodJets; 

    
//     auto CenterOfMomentum = TLorentzVector(0,0,0,ecm); 
    
//     for(size_t i = 0; i < Jets.size(); ++i){
//         for(size_t j = 1; j < Jets.size(); ++j){
//             if (j == i){
//                 continue; 
//             }
//             float Mij = (Jets[i] + Jets[j]).M(); 
//             MassDiff = pow((Mij - DesiredMass), 2);

            
//             MRec = (CenterOfMomentum - (Jets[i] + Jets[j])).M(); 
//             MRecDiff = pow((MRec - DesiredMRec), 2); 
//             Score = (1-chi_squared_frac)*MassDiff + chi_squared_frac*MRecDiff; // The weights on MassDiff and MRecDiff are lifted from Jan's analysis. 
//            // cout << "This is MassDiff: " << MassDiff << endl;  
//             if (Score < ScoreOld){
//                 GoodJets.first = i; 
//                 GoodJets.second = j; 
//                 ScoreOld = Score; 
//             }
//         }

//     }
//     // cout << "This is first index: " << GoodJets.first << endl; 
//     // cout << "This is second index: " << GoodJets.second << endl; 
//     auto recoil_p4 = TLorentzVector(0,0,0,ecm); 
//     recoil_p4 -= (Jets[GoodJets.first] + Jets[GoodJets.second]); 
//     result.push_back(Jets[GoodJets.first] + Jets[GoodJets.second]); 
//     result.push_back(recoil_p4);
//     result.push_back(Jets[GoodJets.first]); 
//     result.push_back(Jets[GoodJets.second]); 
//     return result; 
// }

int PDGFromScoreVec(Vec_f Scores){
    int PDG; 
    size_t idx  = ROOT::VecOps::ArgMax(Scores); 
    if(idx == 0){
        PDG = 1; 
    }
    else if(idx == 1){
        PDG = 5; 
    }
    else if (idx == 2){
        PDG = 4; 
    }
    else if (idx == 3){
        PDG = 3;
    }
    else if (idx == 4){
        PDG = 21; 
    }
    return PDG; 
}


std::pair<Vec_tlv, std::pair<int, int>> get_best_jet_pair(float DesiredMass, float DesiredMRec, float ecm, Vec_tlv Jets, std::vector<Vec_f> scores){
    // Returns a vector holding, in the first entry, a TLV best matched to the desired mass and making the recoil mass in the event closest to a specified value. 
    // In the second entry, the four momentum of the recoil in the event is returned. 
    //Entries 3 and 4 are the individual best jets. 
    Vec_tlv TLVresult; 
    float MassDiff;
    float MRecDiff;
    float Score;  
    float MRec = 9999999999.9; 
    float ScoreOld = 9999999999.9; 

    float chi_squared_frac = 0.2; 
    std::pair<int, int> GoodJets; //indices of the GoodJets 
     
    
    auto CenterOfMomentum = TLorentzVector(0,0,0,ecm); 
    
    for(size_t i = 0; i < Jets.size() - 1; ++i){
        for(size_t j = 1; j < Jets.size(); ++j){
            if (j > i){
                int Jet1PDG = PDGFromScoreVec(scores[i]); 
                int Jet2PDG = PDGFromScoreVec(scores[j]);
                if (Jet1PDG != Jet2PDG){
                    continue; 
                }
                   
                
            
            float Mij = (Jets[i] + Jets[j]).M(); 
            MassDiff = pow((Mij - DesiredMass), 2);

            
            MRec = (CenterOfMomentum - (Jets[i] + Jets[j])).M(); 
            MRecDiff = pow((MRec - DesiredMRec), 2); 
            Score = (1-chi_squared_frac)*MassDiff + chi_squared_frac*MRecDiff; 
           // cout << "This is MassDiff: " << MassDiff << endl;  
           //Veto interpretations that suggest ee --> ZZ / WW --> 4 jets
        //    float ZZScore = (1-chi_squared_frac)*pow((Mij - 91.2),2) + chi_squared_frac*pow((MRec - 91.2), 2); 
        //    float WWScore = (1-chi_squared_frac)*pow((Mij - 80.38),2) + chi_squared_frac*pow((MRec - 80.38), 2);
            // if (ZZScore < Score || WWScore < Score){

            // }

            if (Score < ScoreOld){
                GoodJets.first = i; 
                GoodJets.second = j; 
                ScoreOld = Score; 
            }
          }
        }

    }
    // cout << "This is first index: " << GoodJets.first << endl; 
    // cout << "This is second index: " << GoodJets.second << endl; 


    auto recoil_p4 = TLorentzVector(0,0,0,ecm); 
    recoil_p4 -= (Jets[GoodJets.first] + Jets[GoodJets.second]); 
    TLVresult.push_back(Jets[GoodJets.first] + Jets[GoodJets.second]); 
    TLVresult.push_back(recoil_p4);
    TLVresult.push_back(Jets[GoodJets.first]); 
    TLVresult.push_back(Jets[GoodJets.second]); 
    

    std::pair<Vec_tlv, std::pair<int, int>> result{TLVresult, GoodJets}; 

    return result; 
}





   


Vec_tlv makeLorentzVectors(Vec_rp in) {
    
    Vec_tlv result;
    for (auto & p: in) {
        TLorentzVector tlv;
        tlv.SetXYZM(p.momentum.x, p.momentum.y, p.momentum.z, p.mass);
        result.push_back(tlv);
    }
    return result;
}

Vec_tlv makeLorentzVectors(Vec_mc in) {
    
    Vec_tlv result;
    for (auto & p: in) {
        TLorentzVector tlv;
       // cout << "This is px: " << p.momentum.x << endl; 
       // cout << "This is py: " << p.momentum.y << endl; 
       // cout << "This is pz: " << p.momentum.z << endl; 
        tlv.SetXYZM(p.momentum.x, p.momentum.y, p.momentum.z, p.mass);
        result.push_back(tlv);
    }
    return result;
}

// Vec_tlv makeLorentzVectors(float jets_px, float jets_py, float jets_pz, float jets_e) {
//     Vec_tlv result;
//     TLorentzVector tlv;
//     tlv.SetPxPyPzE(jets_px, jets_py, jets_pz, jets_e);
//     result.push_back(tlv);
//     }
//     return result;
// }

Vec_tlv makeLorentzVectors(Vec_f jets_px, Vec_f jets_py, Vec_f jets_pz, Vec_f jets_e) {
    Vec_tlv result;
    for(int i=0; i<jets_px.size(); i++) {
        TLorentzVector tlv;
        tlv.SetPxPyPzE(jets_px[i], jets_py[i], jets_pz[i], jets_e[i]);
        result.push_back(tlv);
    }
    return result;
}


Vec_i jetTruthFinder(std::vector<std::vector<int>> constituents, Vec_rp reco, Vec_mc mc, Vec_i mcind, bool findGluons = false) {
    // jet truth=finder: match the gen-level partons (eventually with gluons) with the jet constituents
    // matching by mimimizing the sum of dr of the parton and all the jet constituents 

    Vec_tlv genQuarks; // Lorentz-vector of potential partons (gen-level)
    Vec_i genQuarks_pdgId; // corresponding PDG ID
    for(size_t i = 0; i < mc.size(); ++i) {
        int pdgid = abs(mc.at(i).PDG);
        if(pdgid > 6 and not findGluons) continue; // only quarks 
        if(pdgid > 6 and pdgid != 21 and findGluons) continue; // only quarks and gluons
        TLorentzVector tlv;
        tlv.SetXYZM(mc.at(i).momentum.x,mc.at(i).momentum.y,mc.at(i).momentum.z,mc.at(i).mass);
        genQuarks.push_back(tlv);
        genQuarks_pdgId.push_back(mc.at(i).PDG);
    }

    Vec_tlv recoParticles; // Lorentz-vector of all reconstructed particles
    for(size_t i = 0; i < reco.size(); ++i) {
        auto & p = reco[i];
        TLorentzVector tlv;
        tlv.SetXYZM(p.momentum.x, p.momentum.y, p.momentum.z, p.mass);
        recoParticles.push_back(tlv);
    }

    Vec_i usedIdx;
    Vec_i result;
    for(size_t iJet = 0; iJet < constituents.size(); ++iJet) {
        Vec_d dr;
        for(size_t iGen = 0; iGen < genQuarks.size(); ++iGen) {
            if(std::find(usedIdx.begin(), usedIdx.end(), iGen) != usedIdx.end()) {
                dr.push_back(1e99); // set infinite dr, skip
                continue;
            }
            dr.push_back(0);
            for(size_t i = 0; i < constituents[iJet].size(); ++i) {
                dr[iGen] += recoParticles[constituents[iJet][i]].DeltaR(genQuarks[iGen]);
            }
        }
        int maxDrIdx = std::min_element(dr.begin(),dr.end()) - dr.begin();
        usedIdx.push_back(maxDrIdx);
        result.push_back(genQuarks_pdgId[maxDrIdx]);

    }
    return result;
}


Vec_i jetTruthFinder(Vec_tlv Jets_Tlv, Vec_mc mc, bool findGluons = false) {
    // jet truth=finder: match the gen-level partons (eventually with gluons) with the jet constituents
    // matching by mimimizing the sum of dr of the parton and all the jet constituents 
    // Built off of Jan Eysermans' jetTruthFinder functon. 

    Vec_tlv genQuarks; // Lorentz-vector of potential partons (gen-level)
    Vec_i genQuarks_pdgId; // corresponding PDG ID
    for(size_t i = 0; i < mc.size(); ++i) {
        int pdgid = abs(mc.at(i).PDG);
        if(pdgid > 6 and not findGluons) continue; // only quarks 
        if(pdgid > 6 and pdgid != 21 and findGluons) continue; // only quarks and gluons
        TLorentzVector tlv;
        tlv.SetXYZM(mc.at(i).momentum.x,mc.at(i).momentum.y,mc.at(i).momentum.z,mc.at(i).mass);
        genQuarks.push_back(tlv);
        genQuarks_pdgId.push_back(mc.at(i).PDG);
    }

    Vec_i usedIdx;
    Vec_i result;
    for(size_t iJet = 0; iJet < Jets_Tlv.size(); ++iJet) {
        Vec_d dr;
        for(size_t iGen = 0; iGen < genQuarks.size(); ++iGen) {
            if(std::find(usedIdx.begin(), usedIdx.end(), iGen) != usedIdx.end()) {
                dr.push_back(1e99); // set infinite dr, skip
                continue;
            }
            dr.push_back(0);
            
            dr[iGen] += Jets_Tlv[iJet].DeltaR(genQuarks[iGen]);
            
        }
        int maxDrIdx = std::min_element(dr.begin(),dr.end()) - dr.begin();
        usedIdx.push_back(maxDrIdx);
        result.push_back(genQuarks_pdgId[maxDrIdx]);

    }
    return result;
}

std::pair<Vec_i, Vec_i> BestJetTruthFinder(Vec_tlv Jets_Tlv, Vec_mc mc, int qIdx, int qBarIdx, bool findGluons = false) {
    // To be used on the best 2 jets in order to return both their PDG and whether or not they form the associated Z in ZH production. 
    // Built off of Jan Eysermans' jetTruthFinder functon. 

    Vec_tlv genQuarks; // Lorentz-vector of potential partons (gen-level)
    Vec_i genQuarks_pdgId; // corresponding PDG ID
    Vec_i genQuarks_Idx; // correspondning Index in the MC collection 
    for(size_t i = 0; i < mc.size(); ++i) {
        int pdgid = abs(mc.at(i).PDG);
        if(pdgid > 6 and not findGluons) continue; // only quarks 
        if(pdgid > 6 and pdgid != 21 and findGluons) continue; // only quarks and gluons
       //cout << "This is an allowed PDG: " << mc.at(i).PDG << endl; 
        TLorentzVector tlv;
        tlv.SetXYZM(mc.at(i).momentum.x,mc.at(i).momentum.y,mc.at(i).momentum.z,mc.at(i).mass);
        genQuarks.push_back(tlv);
        genQuarks_pdgId.push_back(mc.at(i).PDG);
        genQuarks_Idx.push_back(i); 
    }

    Vec_i usedIdx;
    Vec_i PDGresult;
    Vec_i ZTruthresult; 
    std::pair<int, int> IdxHolder; 
    std::pair<Vec_i, Vec_i> result; 
    IdxHolder.first = 0; 
    IdxHolder.second = 0; 

    for(size_t iJet = 0; iJet < Jets_Tlv.size(); ++iJet) {
        
        Vec_d dr;
        for(size_t iGen = 0; iGen < genQuarks.size(); ++iGen) {
            if(std::find(usedIdx.begin(), usedIdx.end(), iGen) != usedIdx.end()) {
                dr.push_back(1e99); // set infinite dr, skip
                continue;
            }
            dr.push_back(0);
            
            dr[iGen] += Jets_Tlv[iJet].DeltaR(genQuarks[iGen]);
            
        }
        int maxDrIdx = std::min_element(dr.begin(),dr.end()) - dr.begin();
        usedIdx.push_back(maxDrIdx);
        PDGresult.push_back(genQuarks_pdgId[maxDrIdx]);
        if(iJet == 0){
            //If Jet1
            IdxHolder.first = genQuarks_Idx[maxDrIdx]; 

        }
        if(iJet == 1){
            //if Jet2
            IdxHolder.second = genQuarks_Idx[maxDrIdx]; 
        }
    }
        // cout << "This is first index: " << IdxHolder.first << endl;  
        // cout << "This is the genQuark idx: " << qIdx << endl; 
        // cout << "This is second index: " << IdxHolder.second << endl; 
        // cout << "This is the genAntiquark idx: " << qBarIdx << endl;
    if((IdxHolder.first == qIdx && IdxHolder.second == qBarIdx) || (IdxHolder.first == qBarIdx && IdxHolder.second == qIdx)){

        ZTruthresult.push_back(1);
    }
    result.first = PDGresult; 
    result.second = ZTruthresult; 
    return result;
}







int NumOfEntries(Vec_f in) {
    int result = in.size(); 
    return result; 
}

int NumOfEntries(Vec_i in) {
    int result = in.size(); 
    return result; 
}




/*
 std::array<>SetHiggsId(Vec_rp in){
    Vec_f result;
    for (auto & p: in){
    float higgsID = 25; 
    result.push_back(higgsID);
    }
    return result; 
}
*/

Vec_tlv makeElectronTlv(){
    Vec_tlv result; 
    TLorentzVector tlv; 
    tlv.SetXYZM(0, 0, 120.00, 0.000511);
    result.push_back(tlv); 
    return result; 
}

Vec_tlv makePositronTlv(){
    Vec_tlv result; 
    TLorentzVector tlv; 
    tlv.SetXYZM(0, 0, -120.00, 0.000511); 
    result.push_back(tlv);
    return result; 
}

float tlvSanity(Vec_tlv in){
    float result = 1.34; 
    cout << "This is px: " << in[0].Px() << endl; 
    cout << "This is py: " << in[0].Py() << endl; 
    cout << "This is pz: " << in[0].Pz() << endl; 
    return result; 
}

//Below are the functions to create branches that can be processed by MELA. Lists of std::arrays are the general input to MELA. 
//These functions, like the ones that calculate angles, could be improved by letting them take Vec_rp's as input rather than Vec_tlv's.



std::array<int, 1> SetHiggsId(){
    std::array<int, 1> HiggsIdxArray = {25};
    return HiggsIdxArray; 
}

std::array<float, 1> SetHiggsPt(Vec_tlv in){
    double_t HiggsPtD = in[0].Pt(); 
    float HiggsPtF = static_cast<float>(HiggsPtD);
    std::array<float, 1> HiggsPtArray = {HiggsPtF}; 
    return HiggsPtArray; 
}

std::array<float, 1> SetHiggsEta(Vec_tlv in){
    double_t HiggsEtaD = in[0].Eta(); 
    float HiggsEtaF = static_cast<float>(HiggsEtaD); 
    std::array<float, 1> HiggsEtaArray = {HiggsEtaF}; 
    return HiggsEtaArray; 
}

std::array<float, 1> SetHiggsPhi(Vec_tlv in){
    double_t HiggsPhiD = in[0].Phi(); 
    float HiggsPhiF = static_cast<float>(HiggsPhiD); 
    std::array<float, 1> HiggsPhiArray = {HiggsPhiF}; 
    return HiggsPhiArray; 
}

std::array<float, 1> SetHiggsM(Vec_tlv in){
    double_t HiggsMD = in[0].M();
    float HiggsMF = static_cast<float>(HiggsMD);
    std::array<float, 1> HiggsM = {HiggsMF}; 
    return HiggsM; 
}

std::vector<int> DesiredDaughters(){
    std::vector<int> vect {13, -13, 25}; 
    return vect; 
}

/*
float SetAssocId(){
    return 23; 
}
*/



std::array<int,2> SetAssocId(float in1, float in2){
    std::array<int,2> AssocIdArray = {static_cast<int>(in1), static_cast<int>(in2)}; 
    return AssocIdArray; 
}

std::array<float, 2> SetAssocPt(Vec_tlv lep1, Vec_tlv lep2){
    double_t lep1PtD = lep1[0].Pt(); 
    float lep1PtF = static_cast<float>(lep1PtD);

    double_t lep2PtD = lep2[0].Pt(); 
    float lep2PtF = static_cast<float>(lep2PtD);
    std::array<float, 2> AssocPtArray = {lep1PtF, lep2PtF}; 
    return AssocPtArray; 
}

std::array<float, 2> SetAssocEta(Vec_tlv lep1, Vec_tlv lep2){
    double_t lep1EtaD = lep1[0].Eta(); 
    float lep1EtaF = static_cast<float>(lep1EtaD);

    double_t lep2EtaD = lep2[0].Eta(); 
    float lep2EtaF = static_cast<float>(lep2EtaD);
    std::array<float, 2> AssocEtaArray = {lep1EtaF, lep2EtaF}; 
    return AssocEtaArray; 
}

std::array<float, 2> SetAssocPhi(Vec_tlv lep1, Vec_tlv lep2){
    double_t lep1PhiD = lep1[0].Phi(); 
    float lep1PhiF = static_cast<float>(lep1PhiD);

    double_t lep2PhiD = lep2[0].Phi(); 
    float lep2PhiF = static_cast<float>(lep2PhiD);
    std::array<float, 2> AssocPhiArray = {lep1PhiF, lep2PhiF}; 
    return AssocPhiArray; 
}

std::array<float, 2> SetAssocM(Vec_tlv lep1, Vec_tlv lep2){
    double_t lep1MD = lep1[0].M(); 
    float lep1MF = static_cast<float>(lep1MD);

    double_t lep2MD = lep2[0].M(); 
    float lep2MF = static_cast<float>(lep2MD);
    std::array<float, 2> AssocM = {lep1MF, lep2MF}; 
    return AssocM; 
}


Vec_f MakeScoreVector(float ScoreQ, float ScoreB, float ScoreC, float ScoreS, float ScoreG){
    Vec_f result; 
    result.push_back(ScoreQ); 
    result.push_back(ScoreB); 
    result.push_back(ScoreC); 
    result.push_back(ScoreS); 
    result.push_back(ScoreG); 
    return result; 
}


// Deprecated way of getting best Jets with PDGs

// std::tuple<Vec_tlv, std::pair<int, int>, Vec_f, Vec_f> BestJetsWithPDG(Vec_tlv jets, std::vector<Vec_f> scores){
//    std::pair<Vec_tlv, std::pair<int, int>> temp = get_best_jet_pair(91.2, 125.0, 240, jets); 
//    Vec_tlv TLVResult = temp.first; 
//    //Determine PDGs: 
//    int Jet1PDG = PDGFromScoreVec(scores[temp.second.first]); 
//    int Jet2PDG = PDGFromScoreVec(scores[temp.second.second]);
//    std::pair<int, int> PDGPair; 
//    PDGPair.first = Jet1PDG; 
//    PDGPair.second = Jet2PDG; 

//    Vec_f Jet1Scores = scores[temp.second.first];
//    Vec_f Jet2Scores = scores[temp.second.second];


//    std::tuple<Vec_tlv, std::pair<int, int>, Vec_f, Vec_f> result {TLVResult, PDGPair, Jet1Scores, Jet2Scores}; 
//    return result; 
// }



//The calculations for the angles below follow the naming conventions shown in the diagram in this paper: https://arxiv.org/pdf/1208.4018.pdf

//calculate cosine(theta1). This is done in the rest frame of q1. 
float CosineTheta1(Vec_tlv q1, Vec_tlv q2, Vec_tlv q11){
    float Cos_1 = -999.0; 
    ROOT::Math::PxPyPzMVector Vecq1; 
    Vecq1.SetCoordinates(q1[0].Px(), q1[0].Py(), q1[0].Pz(), q1[0].M());

    ROOT::Math::PxPyPzMVector Vecq2; 
    Vecq2.SetCoordinates(q2[0].Px(), q2[0].Py(), q2[0].Pz(), q2[0].M());

    ROOT::Math::PxPyPzMVector Vecq11; 
    Vecq11.SetCoordinates(q11[0].Px(), q11[0].Py(), q11[0].Pz(), q11[0].M());

     
    auto Beta_vec = Vecq1.BoostToCM(); 

    auto COM_Boost = ROOT::Math::Boost(Beta_vec); 


    ROOT::Math::PxPyPzMVector Vecq11Boosted; 
    Vecq11Boosted = COM_Boost*Vecq11; 

    ROOT::Math::PxPyPzMVector Vecq2Boosted; 
    Vecq2Boosted = COM_Boost*Vecq2; 

    ROOT::Math::XYZVector Vecq11BoostedP3; 
    Vecq11BoostedP3.SetXYZ(Vecq11Boosted.x(), Vecq11Boosted.y(), Vecq11Boosted.z()); 

    ROOT::Math::XYZVector Vecq2BoostedP3; 
    Vecq2BoostedP3.SetXYZ(Vecq2Boosted.x(), Vecq2Boosted.y(), Vecq2Boosted.z()); 

   float Mag_Boosted_Vecq2 = sqrt(Vecq2BoostedP3.mag2());

   float Mag_Boosted_Vecq11 = sqrt(Vecq11BoostedP3.mag2());

   float Dot_Product_q2_q11 = Vecq11BoostedP3.Dot(Vecq2BoostedP3);

    Cos_1 = -1*Dot_Product_q2_q11/(Mag_Boosted_Vecq2 * Mag_Boosted_Vecq11);

    return Cos_1; 



} 

//calculate cosine(theta2). This is done in the rest frame of q2. 
float CosineTheta2(Vec_tlv q1, Vec_tlv q2, Vec_tlv q21){
    float Cos_2 = -999.0; 
    ROOT::Math::PxPyPzMVector Vecq1; 
    Vecq1.SetCoordinates(q1[0].Px(), q1[0].Py(), q1[0].Pz(), q1[0].M());

    ROOT::Math::PxPyPzMVector Vecq2; 
    Vecq2.SetCoordinates(q2[0].Px(), q2[0].Py(), q2[0].Pz(), q2[0].M());

    ROOT::Math::PxPyPzMVector Vecq21; 
    Vecq21.SetCoordinates(q21[0].Px(), q21[0].Py(), q21[0].Pz(), q21[0].M());

     
    auto Beta_vec = Vecq2.BoostToCM(); 

    auto COM_Boost = ROOT::Math::Boost(Beta_vec); 


    ROOT::Math::PxPyPzMVector Vecq21Boosted; 
    Vecq21Boosted = COM_Boost*Vecq21; 

    ROOT::Math::PxPyPzMVector Vecq1Boosted; 
    Vecq1Boosted = COM_Boost*Vecq1; 

    ROOT::Math::XYZVector Vecq21BoostedP3; 
    Vecq21BoostedP3.SetXYZ(Vecq21Boosted.x(), Vecq21Boosted.y(), Vecq21Boosted.z()); 

    ROOT::Math::XYZVector Vecq1BoostedP3; 
    Vecq1BoostedP3.SetXYZ(Vecq1Boosted.x(), Vecq1Boosted.y(), Vecq1Boosted.z()); 

   float Mag_Boosted_Vecq1 = sqrt(Vecq1BoostedP3.mag2());

   float Mag_Boosted_Vecq21 = sqrt(Vecq21BoostedP3.mag2());

   float Dot_Product_q1_q21 = Vecq21BoostedP3.Dot(Vecq1BoostedP3);

    Cos_2 = -1*Dot_Product_q1_q21/(Mag_Boosted_Vecq1 * Mag_Boosted_Vecq21);

    return Cos_2; 



} 

//Calculate phi. This is done in the rest frame of X. 
float AnglePhi(Vec_tlv X, Vec_tlv q1, Vec_tlv q11, Vec_tlv q12, Vec_tlv q21, Vec_tlv q22){
    float Phi = -990.0; 
    
    ROOT::Math::PxPyPzMVector VecX; 
    VecX.SetCoordinates(X[0].Px(), X[0].Py(), X[0].Pz(), X[0].M());

    ROOT::Math::PxPyPzMVector Vecq1; 
    Vecq1.SetCoordinates(q1[0].Px(), q1[0].Py(), q1[0].Pz(), q1[0].M());

    ROOT::Math::PxPyPzMVector Vecq11; 
    Vecq11.SetCoordinates(q11[0].Px(), q11[0].Py(), q11[0].Pz(), q11[0].M());

    ROOT::Math::PxPyPzMVector Vecq12; 
    Vecq12.SetCoordinates(q12[0].Px(), q12[0].Py(), q12[0].Pz(), q12[0].M());

    ROOT::Math::PxPyPzMVector Vecq21; 
    Vecq21.SetCoordinates(q21[0].Px(), q21[0].Py(), q21[0].Pz(), q21[0].M());

    ROOT::Math::PxPyPzMVector Vecq22; 
    Vecq22.SetCoordinates(q22[0].Px(), q22[0].Py(), q22[0].Pz(), q22[0].M());
    
    auto Beta_vec = VecX.BoostToCM(); 

    auto COM_Boost = ROOT::Math::Boost(Beta_vec); 
        
    //Calculating n1: 

    ROOT::Math::PxPyPzMVector Vecq11Boosted = COM_Boost*Vecq11; 
    ROOT::Math::PxPyPzMVector Vecq12Boosted = COM_Boost*Vecq12; 


    ROOT::Math::XYZVector Vecq11BoostedP3; 
    Vecq11BoostedP3.SetXYZ(Vecq11Boosted.x(), Vecq11Boosted.y(), Vecq11Boosted.z()); 

    ROOT::Math::XYZVector Vecq12BoostedP3; 
    Vecq12BoostedP3.SetXYZ(Vecq12Boosted.x(), Vecq12Boosted.y(), Vecq12Boosted.z()); 

    
    ROOT::Math::XYZVector Cross_q11_q12 = Vecq11BoostedP3.Cross(Vecq12BoostedP3); 

    ROOT::Math::XYZVector n1 = Cross_q11_q12/sqrt(Cross_q11_q12.mag2()); 

    //Calculating n2: 

    ROOT::Math::PxPyPzMVector Vecq21Boosted = COM_Boost*Vecq21;
    ROOT::Math::PxPyPzMVector Vecq22Boosted = COM_Boost*Vecq22;


    ROOT::Math::XYZVector Vecq21BoostedP3; 
    Vecq21BoostedP3.SetXYZ(Vecq21Boosted.x(), Vecq21Boosted.y(), Vecq21Boosted.z()); 

    ROOT::Math::XYZVector Vecq22BoostedP3; 
    Vecq22BoostedP3.SetXYZ(Vecq22Boosted.x(), Vecq22Boosted.y(), Vecq22Boosted.z()); 

    
    ROOT::Math::XYZVector Cross_q21_q22 = Vecq21BoostedP3.Cross(Vecq22BoostedP3); 

    ROOT::Math::XYZVector n2 = Cross_q21_q22/sqrt(Cross_q21_q22.mag2()); 

    //Calculating Phi itself: 
    ROOT::Math::PxPyPzMVector Vecq1Boosted = COM_Boost*Vecq1; 

    ROOT::Math::XYZVector Vecq1BoostedP3; 
    Vecq1BoostedP3.SetXYZ(Vecq1Boosted.x(), Vecq1Boosted.y(), Vecq1Boosted.z()); 

    ROOT::Math::XYZVector Cross_n1_n2 = n1.Cross(n2); 
    float Dot_n1_n2 = n1.Dot(n2); 

    float Dot_Z_n1Xn2 = Vecq1BoostedP3.Dot(Cross_n1_n2); 
    float Mag_Dot_Z_n1Xn2 = abs(Dot_Z_n1Xn2); 

    float inv_cos_Dot_n1_n2 = acos(-1*Dot_n1_n2); 

    Phi = Dot_Z_n1Xn2/Mag_Dot_Z_n1Xn2 * inv_cos_Dot_n1_n2; 
    
    return Phi; 






}

float SMWeights(std::array<int, 1>  HiggsID, Vec_tlv higgsTlv, std::array<int, 2> AssociatedParticleID, Vec_tlv AssocTlvNeg, Vec_tlv AssocTlvPos){
    SpinZeroCouplings coupl_H; 

    TLorentzVector null;
    null.SetXYZM(0, 0, 0, 0);
    float prob = 0.0; 
/*
    coupl_H.Hzzcoupl[TCOUPLINGSBASE_HH::gHIGGS_VV_1][0]=2; 
    coupl_H.Hzzcoupl[TCOUPLINGSBASE_HH::gHIGGS_VV_1][1]=0; 

    coupl_H.Hzzcoupl[TCOUPLINGSBASE_HH::gHIGGS_VV_4][0]=0; 
    coupl_H.Hzzcoupl[TCOUPLINGSBASE_HH::gHIGGS_VV_4][1]=0; 
*/
    coupl_H.SetHVVCouplings(0, 2, 0, false, 1);
    coupl_H.SetHVVCouplings(3,0,0,false,1);

// First index = Resonance 1 - 1= 0, second index = ghz1, third index = real component
    m.selfDHzzcoupl[0][0][0] = 2; 

    SimpleParticle_t momSimpleParticle = SimpleParticle_t(0, null); 
    SimpleParticle_t lepSimpleParticle = SimpleParticle_t(HiggsID[0], higgsTlv[0]); 
    SimpleParticle_t AssocSimpleParticleNeg = SimpleParticle_t(AssociatedParticleID[0], AssocTlvNeg[0]); 
    SimpleParticle_t AssocSimpleParticlePos = SimpleParticle_t(AssociatedParticleID[1], AssocTlvPos[0]); 

    
    SimpleParticleCollection_t*  mothers = new SimpleParticleCollection_t{0};
    SimpleParticleCollection_t*  leptons = new SimpleParticleCollection_t{lepSimpleParticle};
    SimpleParticleCollection_t* jets = new SimpleParticleCollection_t{AssocSimpleParticleNeg, AssocSimpleParticlePos};  

    

    m.setInputEvent(leptons, jets, 0, 1); 
    m.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::Lep_ZH); 

    //cout << "This is the value of the coupling in SMWeights: " << m.selfDHzzcoupl[0][0][0] << endl; 
    m.computeProdP(prob, 1); 
    m.resetInputEvent(); 
    return prob; 
    



    

}


float BSMWeights(std::array<int, 1>  HiggsID, Vec_tlv higgsTlv, std::array<int, 2> AssociatedParticleID, Vec_tlv AssocTlvNeg, Vec_tlv AssocTlvPos){
    SpinZeroCouplings coupl_H; 

    TLorentzVector null;
    null.SetXYZM(0, 0, 0, 0);
    float prob = 0.0; 
// First index = Resonance 1 - 1= 0, second index = ghz4, third index = real component
    m.selfDHzzcoupl[0][3][0] = 1; 

    SimpleParticle_t momSimpleParticle = SimpleParticle_t(0, null); 
    SimpleParticle_t lepSimpleParticle = SimpleParticle_t(HiggsID[0], higgsTlv[0]); 
    SimpleParticle_t AssocSimpleParticleNeg = SimpleParticle_t(AssociatedParticleID[0], AssocTlvNeg[0]); 
    SimpleParticle_t AssocSimpleParticlePos = SimpleParticle_t(AssociatedParticleID[1], AssocTlvPos[0]); 

    
    SimpleParticleCollection_t*  mothers = new SimpleParticleCollection_t{0};
    SimpleParticleCollection_t*  leptons = new SimpleParticleCollection_t{lepSimpleParticle};
    SimpleParticleCollection_t* jets = new SimpleParticleCollection_t{AssocSimpleParticleNeg, AssocSimpleParticlePos};  

    

    m.setInputEvent(leptons, jets, 0, 1); 
    m.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::Lep_ZH); 

    
    m.computeProdP(prob, 1); 
    m.resetInputEvent(); 
    return prob; 
}

pair<string, pair<float, float>> makeCouplingPairs(string CouplingName, float Real, float Imaginary){
    pair <float, float> num_pair; 
    pair <string, pair<float, float>> result_pair; 
    num_pair = make_pair(Real, Imaginary);
    result_pair = make_pair(CouplingName, num_pair); 
    return result_pair; 
}

template<typename T>
std::vector<T> createCouplingVector(std::initializer_list<T> args) {
    return std::vector<T>(args);
}

/*
std::vector<pair<string, pair<float, float>>> makeCouplingInput(pair<string, pair<float, float>> CouplingPair, ...){
    std::vector<pair<string, pair<float, float>>> result;
    

    return result; 
}
*/

/*
float Weights(std::array<int, 1>  HiggsID, Vec_tlv higgsTlv, std::array<int, 2> AssociatedParticleID, Vec_tlv AssocTlvNeg, Vec_tlv AssocTlvPos, pair<string, pair<float, float>> ghz1_input){
    SpinZeroCouplings coupl_H; 

    TLorentzVector null;
    null.SetXYZM(0, 0, 0, 0);
    float prob = 0.0; 

    build_map(ghz1_input); 
    set_m_map(); 
   
    double in_map_array[2] = {in_map["ghz1"].first, in_map["ghz1"].second}; 
    m_map["ghz1"][0] = in_map["ghz1"].first; 

    SimpleParticle_t momSimpleParticle = SimpleParticle_t(0, null); 
    SimpleParticle_t lepSimpleParticle = SimpleParticle_t(HiggsID[0], higgsTlv[0]); 
    SimpleParticle_t AssocSimpleParticleNeg = SimpleParticle_t(AssociatedParticleID[0], AssocTlvNeg[0]); 
    SimpleParticle_t AssocSimpleParticlePos = SimpleParticle_t(AssociatedParticleID[1], AssocTlvPos[0]); 

    
    SimpleParticleCollection_t*  mothers = new SimpleParticleCollection_t{0};
    SimpleParticleCollection_t*  leptons = new SimpleParticleCollection_t{lepSimpleParticle};
    SimpleParticleCollection_t* jets = new SimpleParticleCollection_t{AssocSimpleParticleNeg, AssocSimpleParticlePos};  

    

    m.setInputEvent(leptons, jets, 0, 1); 
    m.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::Lep_ZH); 

    cout << "This is the value of the coupling in the General function: " << m.selfDHzzcoupl[0][0][0] << endl; 
    m.computeProdP(prob, 1); 
    m.resetInputEvent(); 
    return prob; 
}
*/

float Weights(std::array<int, 1>  HiggsID, Vec_tlv higgsTlv, std::array<int, 2> AssociatedParticleID, Vec_tlv AssocTlvNeg, Vec_tlv AssocTlvPos, std::vector<pair<string, pair<float, float>>> CouplingInput){
    SpinZeroCouplings coupl_H; 

    TLorentzVector null;
    null.SetXYZM(0, 0, 0, 0);
    float prob = 0.0; 

    set_m_map(); 
    for (pair<string, pair<float, float>> element : CouplingInput){
        m_map[element.first][0] = element.second.first; // Real component of the coupling 
        m_map[element.first][1] = element.second.second; // Imaginary component of the coupling 
    }

    SimpleParticle_t momSimpleParticle = SimpleParticle_t(0, null); 
    SimpleParticle_t lepSimpleParticle = SimpleParticle_t(HiggsID[0], higgsTlv[0]); 
    SimpleParticle_t AssocSimpleParticleNeg = SimpleParticle_t(AssociatedParticleID[0], AssocTlvNeg[0]); 
    SimpleParticle_t AssocSimpleParticlePos = SimpleParticle_t(AssociatedParticleID[1], AssocTlvPos[0]); 

    
    SimpleParticleCollection_t*  mothers = new SimpleParticleCollection_t{0};
    SimpleParticleCollection_t*  leptons = new SimpleParticleCollection_t{lepSimpleParticle};
    SimpleParticleCollection_t* jets = new SimpleParticleCollection_t{AssocSimpleParticleNeg, AssocSimpleParticlePos};  

    

    m.setInputEvent(leptons, jets, 0, 1); 
    if(AssociatedParticleID[0] == 11 || AssociatedParticleID[0] == 13){
        m.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::Lep_ZH); 
       // cout << "Currently hitting Lep_ZH" << endl; 
    }
    else {
        m.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::Had_ZH); 
       // cout << "Currently hitting Had_ZH" << endl;
    }
  //  cout << "This is the value of the ghz1 coupling in the General function: " << m.selfDHzzcoupl[0][0][0] << endl;
  //   cout << "This is the value of the ghz4 coupling in the General function: " << m.selfDHzzcoupl[0][3][0] << endl;  
    m.computeProdP(prob, 1); 
    m.resetInputEvent(); 
    return prob; 
}


float Weights(std::array<int, 1>  HiggsID, TLorentzVector higgsTlv, std::array<int, 2> AssociatedParticleID, TLorentzVector AssocTlvNeg, TLorentzVector AssocTlvPos, std::vector<pair<string, pair<float, float>>> CouplingInput){
    SpinZeroCouplings coupl_H; 

    TLorentzVector null;
    null.SetXYZM(0, 0, 0, 0);
    float prob = 0.0; 

    set_m_map(); 
    for (pair<string, pair<float, float>> element : CouplingInput){
        m_map[element.first][0] = element.second.first; // Real component of the coupling 
        m_map[element.first][1] = element.second.second; // Imaginary component of the coupling 
    }

    SimpleParticle_t momSimpleParticle = SimpleParticle_t(0, null); 
    SimpleParticle_t lepSimpleParticle = SimpleParticle_t(HiggsID[0], higgsTlv); 
    SimpleParticle_t AssocSimpleParticleNeg = SimpleParticle_t(AssociatedParticleID[0], AssocTlvNeg); 
    SimpleParticle_t AssocSimpleParticlePos = SimpleParticle_t(AssociatedParticleID[1], AssocTlvPos); 

    
    SimpleParticleCollection_t*  mothers = new SimpleParticleCollection_t{0};
    SimpleParticleCollection_t*  leptons = new SimpleParticleCollection_t{lepSimpleParticle};
    SimpleParticleCollection_t* jets = new SimpleParticleCollection_t{AssocSimpleParticleNeg, AssocSimpleParticlePos};  

    

    m.setInputEvent(leptons, jets, 0, 1); 
    if(fabs(AssociatedParticleID[0]) == 11 || fabs(AssociatedParticleID[0]) == 13){
        m.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::Lep_ZH); 
       // cout << "Currently hitting Lep_ZH" << endl; 
    }
    else {
        m.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::Had_ZH); 
       // cout << "Currently hitting Had_ZH" << endl;
    }
  //  cout << "This is the value of the ghz1 coupling in the General function: " << m.selfDHzzcoupl[0][0][0] << endl;
  //   cout << "This is the value of the ghz4 coupling in the General function: " << m.selfDHzzcoupl[0][3][0] << endl;  
    m.computeProdP(prob, 1); 
    m.resetInputEvent(); 
    return prob; 
}






//By convention for the diagram describing the ZH process in this diagram: https://arxiv.org/pdf/1309.4819.pdf, Z1 = Z* propagator and the leptons associated with it (Z1_lept, Z1_lept2) are the colliding e-e+ pair. Z2 is the Z produced in association with the Higgs. 
//For OS lepton pairs, the negative lepton comes first in the arguments.  
//As a note, I'm currently doing gen-level quarks as q = "Z2 lept 1" and qBar = "Z2 lept 2"
//For future reference cos_theta_star = MELAAngles[0], cos_1 = MELAAngles[1], cos_2 = MELAAngles[2], phi = MELAAngles[3], phi1 = MELAAngles[4]
Vec_f MELAAngles(Vec_tlv Z1_lept1, int Z1_lept1Id, Vec_tlv Z1_lept2, int Z1_lept2Id, Vec_tlv Z2_lept1, int Z2_lept1Id, Vec_tlv Z2_lept2, int Z2_lept2Id){    
    float costhetastar = -99; 
    float costheta1 = -99; 
    float costheta2 = -99; 
    float phi = -99; 
    float phi1 = -99; 
    float mVstar = -99; 
    float mV = -99; 
    mVstar = (Z1_lept1[0] + Z1_lept2[0]).M(); 
    mV = (Z2_lept1[0] + Z2_lept2[0]).M(); 
    TUtil::computeAngles(costhetastar, costheta1, costheta2, phi, phi1, Z1_lept1[0], Z1_lept1Id, Z1_lept2[0], Z1_lept2Id, Z2_lept1[0], Z2_lept1Id, Z2_lept2[0], Z2_lept2Id); 
    Vec_f result = {costhetastar, costheta1, costheta2, phi, phi1, mVstar, mV}; 
    return result; 
}

Vec_f MELAAngles(Vec_tlv Z1_lept1, int Z1_lept1Id, Vec_tlv Z1_lept2, int Z1_lept2Id, TLorentzVector Z2_lept1, int Z2_lept1Id, TLorentzVector Z2_lept2, int Z2_lept2Id){    
    float costhetastar = -99; 
    float costheta1 = -99; 
    float costheta2 = -99; 
    float phi = -99; 
    float phi1 = -99; 
    float mVstar = -99; 
    float mV = -99; 
    mVstar = (Z1_lept1[0] + Z1_lept2[0]).M(); 
    mV = (Z2_lept1 + Z2_lept2).M(); 
    TUtil::computeAngles(costhetastar, costheta1, costheta2, phi, phi1, Z1_lept1[0], Z1_lept1Id, Z1_lept2[0], Z1_lept2Id, Z2_lept1, Z2_lept1Id, Z2_lept2, Z2_lept2Id); 
    Vec_f result = {costhetastar, costheta1, costheta2, phi, phi1, mVstar, mV}; 
    return result; 
}

// Vec_f VHAngles( TLorentzVector p4M11, int Z1_lept1Id, TLorentzVector p4M12, int Z1_lept2Id,
//   TLorentzVector p4M21, int Z2_lept1Id,
//   TLorentzVector p4M22, int Z2_lept2Id,
//   TLorentzVector jet1, int jet1Id,
//   TLorentzVector jet2, int jet2Id,
//   TLorentzVector* injet1, int injet1Id, // Gen. partons in the lab frame
//   TLorentzVector* injet2, int injet2Id
//   ){
//     float costhetastar = -99; 
//     float costheta1 = -99; 
//     float costheta2 = -99; 
//     float phi = -99; 
//     float phi1 = -99; 
//     float mVstar = -99; 
//     float mV = -99; 

    

//   }


/* WIP that uses same input as weights functions, i.e. the conventions of daughter jets mothers
Vec_f MELAVHAngles(Vec_tlv Z1_lept1, int Z1_lept1Id, Vec_tlv Z1_lept2, int Z1_lept2Id, Vec_tlv Z2_lept1, int Z2_lept1Id, Vec_tlv Z2_lept2, int Z2_lept2Id){    
    float costhetastar = -99; 
    float costheta1 = -99; 
    float costheta2 = -99; 
    float phi = -99; 
    float phi1 = -99; 
    float mVstar = -99; 
    float mV = -99; 
    TUtil::computeVHAngles(costhetastar, costheta1, costheta2, phi, phi1, mVstar, mV, Z1_lept1[0], Z1_lept1Id, Z1_lept2[0], Z1_lept2Id, Z2_lept1[0], Z2_lept1Id, Z2_lept2[0], Z2_lept2Id); 
    Vec_f result = {costhetastar, costheta1, costheta2, phi, phi1, mVstar, mV}; 
    return result; 
}
*/



} } 

#endif