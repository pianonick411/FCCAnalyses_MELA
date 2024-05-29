#ifndef ZHfunctions_H
#define ZHfunctions_H

#include <cmath>
#include <vector>
#include <math.h>

#include "TLorentzVector.h"
#include "ROOT/RVec.hxx"
#include "edm4hep/ReconstructedParticleData.h"
#include "edm4hep/MCParticleData.h"
#include "edm4hep/ParticleIDData.h"
#include "ReconstructedParticle2MC.h"


namespace FCCAnalyses { namespace ZHfunctions {


// build the Z resonance based on the available leptons. Returns the best lepton pair compatible with the Z mass and recoil at 125 GeV
// technically, it returns a ReconstructedParticleData object with index 0 the di-lepton system, index and 2 the leptons of the pair
struct resonanceBuilder_mass_recoil {
    float m_resonance_mass;
    float m_recoil_mass;
    float chi2_recoil_frac;
    float ecm;
    bool m_use_MC_Kinematics;
    resonanceBuilder_mass_recoil(float arg_resonance_mass, float arg_recoil_mass, float arg_chi2_recoil_frac, float arg_ecm, bool arg_use_MC_Kinematics);
    Vec_rp operator()(Vec_rp legs, Vec_i recind, Vec_i mcind, Vec_rp reco, Vec_mc mc, Vec_i parents, Vec_i daugthers) ;
};

resonanceBuilder_mass_recoil::resonanceBuilder_mass_recoil(float arg_resonance_mass, float arg_recoil_mass, float arg_chi2_recoil_frac, float arg_ecm, bool arg_use_MC_Kinematics) {m_resonance_mass = arg_resonance_mass, m_recoil_mass = arg_recoil_mass, chi2_recoil_frac = arg_chi2_recoil_frac, ecm = arg_ecm, m_use_MC_Kinematics = arg_use_MC_Kinematics;}

Vec_rp resonanceBuilder_mass_recoil::resonanceBuilder_mass_recoil::operator()(Vec_rp legs, Vec_i recind, Vec_i mcind, Vec_rp reco, Vec_mc mc, Vec_i parents, Vec_i daugthers) {

    Vec_rp result;
    result.reserve(3);
    std::vector<std::vector<int>> pairs; // for each permutation, add the indices of the leptons
    int n = legs.size();
  
    if(n > 1) {
        ROOT::VecOps::RVec<bool> v(n);
        std::fill(v.end() - 2, v.end(), true); // helper variable for permutations
        do {
            std::vector<int> pair;
            rp reso;
            reso.charge = 0;
            TLorentzVector reso_lv; 
            for(int i = 0; i < n; ++i) {
                if(v[i]) {
                    pair.push_back(i);
                    reso.charge += legs[i].charge;
                    TLorentzVector leg_lv;

                    if(m_use_MC_Kinematics) { // MC kinematics
                        int track_index = legs[i].tracks_begin;   // index in the Track array
                        int mc_index = ReconstructedParticle2MC::getTrack2MC_index(track_index, recind, mcind, reco);
                        if (mc_index >= 0 && mc_index < mc.size()) {
                            leg_lv.SetXYZM(mc.at(mc_index).momentum.x, mc.at(mc_index).momentum.y, mc.at(mc_index).momentum.z, mc.at(mc_index).mass);
                        }
                    }
                    else { // reco kinematics
                         leg_lv.SetXYZM(legs[i].momentum.x, legs[i].momentum.y, legs[i].momentum.z, legs[i].mass);
                    }

                    reso_lv += leg_lv;
                }
            }

            if(reso.charge != 0) continue; // neglect non-zero charge pairs
            reso.momentum.x = reso_lv.Px();
            reso.momentum.y = reso_lv.Py();
            reso.momentum.z = reso_lv.Pz();
            reso.mass = reso_lv.M();
            result.emplace_back(reso);
            pairs.push_back(pair);

        } while(std::next_permutation(v.begin(), v.end()));
    }
    else {
        std::cout << "ERROR: resonanceBuilder_mass_recoil, at least two leptons required." << std::endl;
        exit(1);
    }
  
    if(result.size() > 1) {
  
        Vec_rp bestReso;
        
        int idx_min = -1;
        float d_min = 9e9;
        for (int i = 0; i < result.size(); ++i) {
            
            // calculate recoil
            auto recoil_p4 = TLorentzVector(0, 0, 0, ecm);
            TLorentzVector tv1;
            tv1.SetXYZM(result.at(i).momentum.x, result.at(i).momentum.y, result.at(i).momentum.z, result.at(i).mass);
            recoil_p4 -= tv1;
      
            auto recoil_fcc = edm4hep::ReconstructedParticleData();
            recoil_fcc.momentum.x = recoil_p4.Px();
            recoil_fcc.momentum.y = recoil_p4.Py();
            recoil_fcc.momentum.z = recoil_p4.Pz();
            recoil_fcc.mass = recoil_p4.M();
            
            TLorentzVector tg;
            tg.SetXYZM(result.at(i).momentum.x, result.at(i).momentum.y, result.at(i).momentum.z, result.at(i).mass);
        
            float boost = tg.P();
            float mass = std::pow(result.at(i).mass - m_resonance_mass, 2); // mass
            float rec = std::pow(recoil_fcc.mass - m_recoil_mass, 2); // recoil
            float d = (1.0-chi2_recoil_frac)*mass + chi2_recoil_frac*rec;
            
            if(d < d_min) {
                d_min = d;
                idx_min = i;
            }

     
        }
        if(idx_min > -1) { 
            bestReso.push_back(result.at(idx_min));
            auto & l1 = legs[pairs[idx_min][0]];
            auto & l2 = legs[pairs[idx_min][1]];
            bestReso.emplace_back(l1);
            bestReso.emplace_back(l2);
        }
        else {
            std::cout << "ERROR: resonanceBuilder_mass_recoil, no mininum found." << std::endl;
            exit(1);
        }
        return bestReso;
    }
    else {
        auto & l1 = legs[0];
        auto & l2 = legs[1];
        result.emplace_back(l1);
        result.emplace_back(l2);
        return result;
    }
}    




struct sel_iso {
    sel_iso(float arg_max_iso);
    float m_max_iso = .25;
    Vec_rp operator() (Vec_rp in, Vec_f iso);
  };

sel_iso::sel_iso(float arg_max_iso) : m_max_iso(arg_max_iso) {};
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>  sel_iso::operator() (Vec_rp in, Vec_f iso) {
    Vec_rp result;
    result.reserve(in.size());
    for (size_t i = 0; i < in.size(); ++i) {
        auto & p = in[i];
        if (iso[i] < m_max_iso) {
            result.emplace_back(p);
        }
    }
    return result;
}

 
// compute the cone isolation for reco particles
struct coneIsolation {

    coneIsolation(float arg_dr_min, float arg_dr_max);
    double deltaR(double eta1, double phi1, double eta2, double phi2) { return TMath::Sqrt(TMath::Power(eta1-eta2, 2) + (TMath::Power(phi1-phi2, 2))); };

    float dr_min = 0;
    float dr_max = 0.4;
    Vec_f operator() (Vec_rp in, Vec_rp rps) ;
};

coneIsolation::coneIsolation(float arg_dr_min, float arg_dr_max) : dr_min(arg_dr_min), dr_max( arg_dr_max ) { };
Vec_f coneIsolation::coneIsolation::operator() (Vec_rp in, Vec_rp rps) {

    Vec_f result;
    result.reserve(in.size());

    std::vector<ROOT::Math::PxPyPzEVector> lv_reco;
    std::vector<ROOT::Math::PxPyPzEVector> lv_charged;
    std::vector<ROOT::Math::PxPyPzEVector> lv_neutral;

    for(size_t i = 0; i < rps.size(); ++i) {

        ROOT::Math::PxPyPzEVector tlv;
        tlv.SetPxPyPzE(rps.at(i).momentum.x, rps.at(i).momentum.y, rps.at(i).momentum.z, rps.at(i).energy);

        if(rps.at(i).charge == 0) lv_neutral.push_back(tlv);
        else lv_charged.push_back(tlv);
    }

    for(size_t i = 0; i < in.size(); ++i) {

        ROOT::Math::PxPyPzEVector tlv;
        tlv.SetPxPyPzE(in.at(i).momentum.x, in.at(i).momentum.y, in.at(i).momentum.z, in.at(i).energy);
        lv_reco.push_back(tlv);
    }

    // compute the isolation (see https://github.com/delphes/delphes/blob/master/modules/Isolation.cc#L154) 
    for (auto & lv_reco_ : lv_reco) {

        double sumNeutral = 0.0;
        double sumCharged = 0.0;

        // charged
        for (auto & lv_charged_ : lv_charged) {
            double dr = coneIsolation::deltaR(lv_reco_.Eta(), lv_reco_.Phi(), lv_charged_.Eta(), lv_charged_.Phi());
            if(dr > dr_min && dr < dr_max) sumCharged += lv_charged_.P();
        }

        // neutral
        for (auto & lv_neutral_ : lv_neutral) {
            double dr = coneIsolation::deltaR(lv_reco_.Eta(), lv_reco_.Phi(), lv_neutral_.Eta(), lv_neutral_.Phi());
            if(dr > dr_min && dr < dr_max) sumNeutral += lv_neutral_.P();
        }

        double sum = sumCharged + sumNeutral;
        double ratio= sum / lv_reco_.P();
        result.emplace_back(ratio);
    }
    return result;
}
 
 
 
// returns missing energy vector, based on reco particles
Vec_rp missingEnergy(float ecm, Vec_rp in, float p_cutoff = 0.0) {
    float px = 0, py = 0, pz = 0, e = 0;
    for(auto &p : in) {
        if (std::sqrt(p.momentum.x * p.momentum.x + p.momentum.y*p.momentum.y) < p_cutoff) continue;
        px += -p.momentum.x;
        py += -p.momentum.y;
        pz += -p.momentum.z;
        e += p.energy;
    }

    Vec_rp ret;
    rp res;
    res.momentum.x = px;
    res.momentum.y = py;
    res.momentum.z = pz;
    res.energy = ecm-e;
    ret.emplace_back(res);
    return ret;
}

// calculate the cosine(theta) of the missing energy vector
float get_cosTheta_miss(Vec_rp met){

    float costheta = 0.;
    if(met.size() > 0) {
        TLorentzVector lv_met;
        lv_met.SetPxPyPzE(met[0].momentum.x, met[0].momentum.y, met[0].momentum.z, met[0].energy);
        costheta = fabs(std::cos(lv_met.Theta()));
    }
    return costheta;
}



// return list of pdg from decay of a list of mother particle
Vec_i gen_decay_list(Vec_i mcin, Vec_mc in, Vec_i ind) {
   // mcin = index of a MC particle in the Particle block
   // in = the Particle collection
   // ind = the block with the indices for the daughters, Particle#1.index
   // returns a vector with the indices (in the Particle block) of the daughters of the particle i

   Vec_i result;

   for (size_t i = 0; i < mcin.size(); ++i) {
        for (size_t j = 0; j < MCParticle::get_list_of_particles_from_decay(mcin[i],in,ind).size(); ++j) {
           //cout << in[MCParticle::get_list_of_particles_from_decay(mcin[i],in,ind)[j]].PDG << endl;
            if(in[MCParticle::get_list_of_particles_from_decay(mcin[i],in,ind)[j]].PDG != 25) {
                result.push_back(in[MCParticle::get_list_of_particles_from_decay(mcin[i], in, ind)[j]].PDG);
            //    cout << in[MCParticle::get_list_of_particles_from_decay(mcin[i], in, ind)[j]].PDG << endl; 
            }
        }
   }
   return result;
}


Vec_i gen_decay_list_inc_higgs(Vec_i mcin, Vec_mc in, Vec_i ind) {
   // mcin = index of a MC particle in the Particle block
   // in = the Particle collection
   // ind = the block with the indices for the daughters, Particle#1.index
   // returns a vector with the indices (in the Particle block) of the daughters of the particle i

   Vec_i result;

   for (size_t i = 0; i < mcin.size(); ++i) {
        for (size_t j = 0; j < MCParticle::get_list_of_particles_from_decay(mcin[i],in,ind).size(); ++j) {
           //cout << in[MCParticle::get_list_of_particles_from_decay(mcin[i],in,ind)[j]].PDG << endl;
            result.push_back(in[MCParticle::get_list_of_particles_from_decay(mcin[i], in, ind)[j]].PDG);
            //    cout << in[MCParticle::get_list_of_particles_from_decay(mcin[i], in, ind)[j]].PDG << endl; 
            
        }
   }
   return result;
}




   


// calculate the number of foward leptons
struct polarAngleCategorization {
    polarAngleCategorization(float arg_thetaMin, float arg_thetaMax);
    float thetaMin = 0;
    float thetaMax = 5;
    int operator() (Vec_rp in);
};

polarAngleCategorization::polarAngleCategorization(float arg_thetaMin, float arg_thetaMax) : thetaMin(arg_thetaMin), thetaMax(arg_thetaMax) {};
int polarAngleCategorization::operator() (Vec_rp in) {

    int nFwd = 0; // number of forward leptons
    for (size_t i = 0; i < in.size(); ++i) {
        auto & p = in[i];
        TLorentzVector lv;
        lv.SetXYZM(p.momentum.x, p.momentum.y, p.momentum.z, p.mass);
        if(lv.Theta() < thetaMin || lv.Theta() > thetaMax) nFwd += 1;
    }
    return nFwd;
}


// compute the lepton momentum resolution
Vec_f leptonResolution_p(Vec_rp leps, Vec_i recind, Vec_i mcind, Vec_rp reco, Vec_mc mc) {
    Vec_f result;
    result.reserve(leps.size());

    for(int i = 0; i < leps.size(); ++i) {
        TLorentzVector reco_;
        reco_.SetXYZM(leps[i].momentum.x, leps[i].momentum.y, leps[i].momentum.z, leps[i].mass);
        int track_index = leps[i].tracks_begin;
        int mc_index = FCCAnalyses::ReconstructedParticle2MC::getTrack2MC_index(track_index, recind, mcind, reco);
        if(mc_index >= 0 && mc_index < (int)mc.size()) {
            TLorentzVector mc_;
            mc_.SetXYZM(mc.at(mc_index).momentum.x, mc.at(mc_index).momentum.y, mc.at(mc_index).momentum.z, mc.at(mc_index).mass);
            result.push_back(reco_.P()/mc_.P());
        }
    }
    return result;
}


// get the index of the matched pdgId in the MC collection
struct sel_pdgID_idx {
    sel_pdgID_idx(int arg_pdg, bool arg_chargeconjugate);
    int m_pdg = 13;
    bool m_chargeconjugate = true;
    ROOT::VecOps::RVec<int>  operator() (Vec_mc in);
};

sel_pdgID_idx::sel_pdgID_idx(int arg_pdg, bool arg_chargeconjugate) : m_pdg(arg_pdg), m_chargeconjugate(arg_chargeconjugate) {};
Vec_i sel_pdgID_idx::sel_pdgID_idx::operator() (Vec_mc in) {
    Vec_i result;
    for(size_t i = 0; i < in.size(); ++i) {
        auto & p = in[i];
        if(m_chargeconjugate) {
            if(std::abs( p.PDG) == std::abs(m_pdg)) result.push_back(i);
        }
        else {
            if(p.PDG == m_pdg) result.push_back(i);
        }
    }
    return result;
}


// acolinearity between two reco particles
float acolinearity(Vec_rp in) {
    if(in.size() < 2) return -999;

    TLorentzVector p1;
    p1.SetXYZM(in[0].momentum.x, in[0].momentum.y, in[0].momentum.z, in[0].mass);

    TLorentzVector p2;
    p2.SetXYZM(in[1].momentum.x, in[1].momentum.y, in[1].momentum.z, in[1].mass);

    TVector3 v1 = p1.Vect();
    TVector3 v2 = p2.Vect();
    return std::acos(v1.Dot(v2)/(v1.Mag()*v2.Mag())*(-1.));
}

// acoplanarity between two reco particles
float acoplanarity(Vec_rp in) {
    if(in.size() < 2) return -999;

    TLorentzVector p1;
    p1.SetXYZM(in[0].momentum.x, in[0].momentum.y, in[0].momentum.z, in[0].mass);

    TLorentzVector p2;
    p2.SetXYZM(in[1].momentum.x, in[1].momentum.y, in[1].momentum.z, in[1].mass);

    float acop = abs(p1.Phi() - p2.Phi());
    if(acop > M_PI) acop = 2 * M_PI - acop;
    acop = M_PI - acop;

    return acop;
}

// perturb the momentum scale with a given constant
struct lepton_momentum_scale {
    lepton_momentum_scale(float arg_scaleunc);
    float scaleunc = 1.;
    Vec_rp operator() (Vec_rp in);
};

lepton_momentum_scale::lepton_momentum_scale(float arg_scaleunc) : scaleunc(arg_scaleunc) {};
Vec_rp lepton_momentum_scale::operator() (Vec_rp in) {
    Vec_rp result;
    result.reserve(in.size());
    for (size_t i = 0; i < in.size(); ++i) {
        auto & p = in[i];
        p.momentum.x = p.momentum.x*(1. + scaleunc);
        p.momentum.y = p.momentum.y*(1. + scaleunc);
        p.momentum.z = p.momentum.z*(1. + scaleunc);
        result.emplace_back(p);
    }
    return result;
}


}}

#endif
