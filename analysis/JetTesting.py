
# analysis config
do_gen = False # replace reco-particles by the corresponding gen particle


import os 
import threading 

import psutil

def print_process_id(): 
    print(threading.current_thread, os.getpid())




# list of processes
processList = {
    # main backgrounds
    #'p8_ee_WW_ecm240': {'fraction':1},
    #'p8_ee_ZZ_ecm240': {'fraction':1},
    #'wzp6_ee_tautau_ecm240': {'fraction':1},
    #'wzp6_ee_mumu_ecm240' if flavor=="mumu" else 'wzp6_ee_ee_Mee_30_150_ecm240': {'fraction':1},

    # rare backgrounds
    #f'wzp6_egamma_eZ_Z{flavor}_ecm240': {'fraction':1},
    #f'wzp6_gammae_eZ_Z{flavor}_ecm240': {'fraction':1},
    #f'wzp6_gaga_{flavor}_60_ecm240': {'fraction':1},
    #'wzp6_gaga_tautau_60_ecm240': {'fraction':1},
    #'wzp6_ee_nuenueZ_ecm240': {'fraction':1},
    
    # signals
    #'wzp6_ee_nunuH_Hbb_ecm240': {'fraction':1},
     f'wzp6_ee_qqH_ecm240': {'fraction':1},
    # f'wzp6_ee_bbH_Hbb_ecm240': {'fraction':1},
    # f'wzp6_ee_bbH_Hcc_ecm240': {'fraction':1},
    # f'wzp6_ee_bbH_Hss_ecm240': {'fraction':1},
    # f'wzp6_ee_bbH_Hgg_ecm240': {'fraction':1},

    # f'wzp6_ee_ccH_Hbb_ecm240': {'fraction':1},
    # f'wzp6_ee_ccH_Hcc_ecm240': {'fraction':1},
    # f'wzp6_ee_ccH_Hss_ecm240': {'fraction':1},
    # f'wzp6_ee_ccH_Hgg_ecm240': {'fraction':1},

    # f'wzp6_ee_ssH_Hbb_ecm240': {'fraction':1},
    # f'wzp6_ee_ssH_Hcc_ecm240': {'fraction':1},
    # f'wzp6_ee_ssH_Hss_ecm240': {'fraction':1},
    # f'wzp6_ee_ssH_Hgg_ecm240': {'fraction':1},

    # f'wzp6_ee_qqH_Hbb_ecm240': {'fraction':1},
    # f'wzp6_ee_qqH_Hcc_ecm240': {'fraction':1},
    # f'wzp6_ee_qqH_Hss_ecm240': {'fraction':1},
    # f'wzp6_ee_qqH_Hgg_ecm240': {'fraction':1},
}


sigProcs = ["wzp6_ee_qqH_ecm240", "wzp6_ee_mumuH_ecm240", "wzp6_ee_bbH_ecm365", "wzp6_ee_bbH_HZZ_ecm240", "wzp6_ee_bbH_Hbb_ecm240"]


# Production tag when running over EDM4Hep centrally produced events, this points to the yaml files for getting sample statistics
prodTag     = "FCCee/winter2023/IDEA/"

# Link to the dictonary that contains all the cross section informations etc...
procDict = "FCCee_procDict_winter2023_IDEA.json"

# additional/custom C++ functions, defined in header files (optional)
includePaths = ["functions.h", "JHUfunctions.h"]


#Optional: output directory, default is local running directory
outputDir   = "jetTests/AHH/"

#f"output_{flavor}/"


# optional: ncpus, default is 4, -1 uses all cores available
nCPUS       = 1

# scale the histograms with the cross-section and integrated luminosity
doScale = True
intLumi = 7200000 # 7.2 /ab


# define some binning for various histograms
bins_p_mu = (2000, 0, 200) # 100 MeV bins
bins_p_mubeeg = (4000, -200, 200)
bins_m_Z = (2000, 0, 200) # 100 MeV bins
bins_p_ll = (200, 0, 200) # 1 GeV bins
bins_recoil = (20000, 0, 200) # 10 MeV bins 
bins_recoil_fine = (20000, 120, 140) # 1 MeV bins 
bins_cosThetaMiss = (10000, 0, 1)
bins_pdgid = (52, -26.0, 26.0)

bins_theta = (500, -5, 5)
bins_eta = (600, -3, 3)
bins_phi = (500, -5, 5)
bins_aco = (400, -4, 4)

bins_count = (50, 0, 50)
bins_charge = (10, -5, 5)
bins_iso = (500, 0, 5)
bins_cat = (10, 0, 10)
bins_resolution = (10000, 0.95, 1.05)

bins_cos = (100, -1.0, 1.0)
bins_phiMELA = (100, -3.15, 3.15)



# build_graph function that contains the analysis logic, cuts and histograms (mandatory)
def build_graph(df, dataset):

    print("build graph", dataset)
    threading.Thread(target=print_process_id).start()
    p = psutil.Process().cpu_num()
    print("THIS IS P", p)
    results = []

    df = df.Alias("Particle0", "Particle#0.index")
    df = df.Alias("Particle1", "Particle#1.index")
    df = df.Alias("MCRecoAssociations0", "MCRecoAssociations#0.index")
    df = df.Alias("MCRecoAssociations1", "MCRecoAssociations#1.index")
    df = df.Alias("Photon0", "Photon#0.index")
    df = df.Alias("Muon0", "Muon#0.index")
    df = df.Alias("Electron0", "Electron#0.index")

    #if dataset in sigProcs: 
    df = df.Define("AllPDGs", "FCCAnalyses::MCParticle::get_pdg(Particle)")



    df = df.Define("d_decays", "FCCAnalyses::MCParticle::get_indices(11, {1, -1, 25}, false, true, false, true)(Particle, Particle1)")
    df = df.Define("u_decays", "FCCAnalyses::MCParticle::get_indices(11, {2, -2, 25}, false, true, false, true)(Particle, Particle1)")
    df = df.Define("s_decays", "FCCAnalyses::MCParticle::get_indices(11, {3, -3, 25}, false, true, false, true)(Particle, Particle1)")
    df = df.Define("c_decays", "FCCAnalyses::MCParticle::get_indices(11, {4, -4, 25}, false, true, false, true)(Particle, Particle1)")
    df = df.Define("b_decays", "FCCAnalyses::MCParticle::get_indices(11, {5, -5, 25}, false, true, false, true)(Particle, Particle1)") 

    results.append(df.Histo1D(("d_decays", "", *bins_count), "d_decays"))
    results.append(df.Histo1D(("u_decays", "", *bins_count), "u_decays"))
    results.append(df.Histo1D(("s_decays", "", *bins_count), "s_decays"))
    results.append(df.Histo1D(("c_decays", "", *bins_count), "c_decays"))
    results.append(df.Histo1D(("b_decays", "", *bins_count), "b_decays"))


    #df = df.Define("full_decays", "FCCAnalyses::MCParticle::get_indices(11, {5, -5, 25}, false, true, false, true)(Particle, Particle1)")
    #df = df.Define("full_decays", "d_decays + u_decays + s_decays + c_decays + b_decays")

    # df = df.Define("full_decays", "FCCAnalyses::MCParticle::get_indices_MotherByIndex(0, {23, 25}, false, false, true, Particle, Particle1)")

    # df = df.Define("full_decays_size", "full_decays.size()")

    df = df.Define("electronMC", "FCCAnalyses::MCParticle::sel_byIndex(4, Particle)")
    df = df.Define("electronVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{electronMC}")
    df = df.Define("electronGenStatus", "FCCAnalyses::MCParticle::get_genStatus(electronVec_MC)")
    df = df.Define("electronSimStatus", "FCCAnalyses::MCParticle::get_simStatus(electronVec_MC)")
    df = df.Define("electronPDG", "FCCAnalyses::MCParticle::get_pdg(electronVec_MC)")
    df = df.Define("electronTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(electronVec_MC)")
    df = df.Define("electronE","FCCAnalyses::MCParticle::get_e(electronVec_MC)" )
    df = df.Define("electronPz", "electronTLV[0].Pz()")
    df = df.Define("electronDaus", "FCCAnalyses::ZHfunctions::gen_decay_list_inc_higgs({4}, Particle, Particle1)")
    # df = df.Define("electronDausIdx", "FCCAnalyses::MCParticle::get_list_of_particles_from_decay(4, Particle, Particle1)")
    # df = df.Redefine("electronDausIdx", "ROOT::VecOps::RVec(electronDausIdx)")
    # df = df.Redefine("electronDausIdx", "ROOT::VecOps::Sort(electronDausIdx)")

    df = df.Define("electronDausIdx", "FCCAnalyses::JHUfunctions::get_gen_daus(4, Particle, Particle1)")

    df = df.Define("positronMC", "FCCAnalyses::MCParticle::sel_byIndex(5, Particle)")
    df = df.Define("positronVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{positronMC}")
    df = df.Define("positronGenStatus", "FCCAnalyses::MCParticle::get_genStatus(positronVec_MC)")
    df = df.Define("positronSimStatus", "FCCAnalyses::MCParticle::get_simStatus(positronVec_MC)")
    df = df.Define("positronPDG", "FCCAnalyses::MCParticle::get_pdg(positronVec_MC)")
    df = df.Define("positronTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(positronVec_MC)")
    df = df.Define("positronE","FCCAnalyses::MCParticle::get_e(positronVec_MC)" )
    df = df.Define("positronPz", "positronTLV[0].Pz()")
    df = df.Define("positronDaus", "FCCAnalyses::ZHfunctions::gen_decay_list_inc_higgs({5}, Particle, Particle1)")

    

    # df = df.Define("electronDaus0", "electronDaus[0]")
    
    

    # df = df.Define("higgsE", "FCCAnalyses::MCParticle::get_pdg(higgs_MC)")


    df = df.Define("q", "FCCAnalyses::MCParticle::sel_byIndex(electronDausIdx[1], Particle)")
    df = df.Define("qVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{q}")
    df = df.Define("qPDG", "FCCAnalyses::MCParticle::get_pdg(qVec_MC)")
    df = df.Define("qE","FCCAnalyses::MCParticle::get_e(qVec_MC)" )
    df = df.Define("qTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(qVec_MC)")
    

    df = df.Define("qBar", "FCCAnalyses::MCParticle::sel_byIndex(electronDausIdx[0], Particle)")
    df = df.Define("qBarVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{qBar}")
    df = df.Define("qBarPDG", "FCCAnalyses::MCParticle::get_pdg(qBarVec_MC)")
    df = df.Define("qBarE","FCCAnalyses::MCParticle::get_e(qBarVec_MC)" )
    df = df.Define("qBarTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(qBarVec_MC)")

    df = df.Define("higgs_MC", "FCCAnalyses::ZHfunctions::sel_pdgID_idx(25,false)(Particle)")
    
    df = df.Define("higgsMC", "FCCAnalyses::MCParticle::sel_byIndex(electronDausIdx[2], Particle)")
    df = df.Define("higgsVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{higgsMC}")
    df = df.Define("higgsPDG", "FCCAnalyses::MCParticle::get_pdg(higgsVec_MC)")
    df = df.Define("higgsMCTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(higgsVec_MC)")
    
    df = df.Define("higgsParents", "FCCAnalyses::MCParticle::get_parentid(higgs_MC, Particle,Particle0)")

    df = df.Define("daughter_higgs", "FCCAnalyses::ZHfunctions::gen_decay_list_inc_higgs(higgs_MC, Particle, Particle1)")

    df = df.Define("daughter_higgs0", "daughter_higgs[0]")

    # df = df.Define("higgsParent_0", "higgsParents[0]")
    # df = df.Define("higgsParent_1", "higgsParents[1]")
    # df = df.Define("higgsParent_2", "higgsParents[2]")

    df = df.Define("Z_Mass_MC", "(qTLV[0] + qBarTLV[0]).M()")
    df = df.Define("Z_pt_MC", "(qTLV[0] + qBarTLV[0]).Pt()")
    
#Setting MELA stuff 
    df = df.Define("LHEAssociatedParticleId", "FCCAnalyses::JHUfunctions::SetAssocId(qPDG[0], qBarPDG[0])")
    df = df.Define("LHEDaughterId", "FCCAnalyses::JHUfunctions::SetHiggsId()")

    df = df.Define("Gen_MELA_Angles", "FCCAnalyses::JHUfunctions::MELAAngles(electronTLV, 11, positronTLV, -11, qTLV, qPDG[0], qBarTLV, qBarPDG[0])")

    df = df.Define("PDGTest", "static_cast<int>(qPDG[0])")
    df = df.Define("Gen_cos_1", "Gen_MELA_Angles[1]")
    df = df.Define("Gen_cos_2", "Gen_MELA_Angles[2]")
    df = df.Define("Gen_phi", "Gen_MELA_Angles[3]")
    df = df.Define("Gen_mVstar", "Gen_MELA_Angles[5]")
    df = df.Define("Gen_mV", "Gen_MELA_Angles[6]")


    df = df.Define("ghz4Pair", 'FCCAnalyses::JHUfunctions::makeCouplingPairs("ghz4", 1.0, 0)')
    df = df.Define("Negghz4Pair", 'FCCAnalyses::JHUfunctions::makeCouplingPairs("ghz4", -1.0, 0)')
    df = df.Define("BSMVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz4Pair})')
    # df = df.Define("MixtureVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz1Pair, ghz4Pair})')
    # df = df.Define("NegMixtureVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz1Pair, Negghz4Pair})')

    df = df.Define("BSMWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, qTLV, qBarTLV, BSMVec)')

    # df = df.Define("full_decays_1", "full_decays[1]")
    # df = df.Define("full_decays_2", "full_decays[2]")
    # df = df.Define("full_decays_3", "full_decays[3]")

    # df = df.Define("Prompt_q", "FCCAnalyses::MCParticle::sel_byIndex(b_decays[0], Particle)") 
    # df = df.Define("Prompt_qMCvec", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{Prompt_q}")
    # df = df.Define("Prompt_qTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(Prompt_qMCvec)")

    # df = df.Define("Prompt_qbar", "FCCAnalyses::MCParticle::sel_byIndex(b_decays[1], Particle)") 
    # df = df.Define("Prompt_qbarMCvec", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{Prompt_qbar}")
    # df = df.Define("Prompt_qbarTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(Prompt_qbarMCvec)")

    # df = df.Define("Z_MC_TLV", "Prompt_qTLV[0] + Prompt_qbarTLV[0]")


    # df = df.Define("higgsMC", "FCCAnalyses::MCParticle::sel_byIndex(b_decays[3], Particle)")
    # df = df.Define("higgsVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{higgsMC}")
    # df = df.Define("higgsGenStatus", "FCCAnalyses::MCParticle::get_genStatus(higgsVec_MC)")
    # df = df.Define("higgsSimStatus", "FCCAnalyses::MCParticle::get_simStatus(higgsVec_MC)")
    # df = df.Define("higgsMCTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(higgsVec_MC)")




    # define cutflow variables
    for i in range(0, 20):
        df = df.Define("cut%d"%i, "%d"%i)

    df = df.Define("nominal_weight", "1.0")

    #Get a list of all muons
    df = df.Define("muons", "FCCAnalyses::ReconstructedParticle::get(Muon0, ReconstructedParticles)")
    df = df.Define("muons_p", "FCCAnalyses::ReconstructedParticle::get_p(muons)[0]")

    df = df.Define("electrons", "FCCAnalyses::ReconstructedParticle::get(Electron0, ReconstructedParticles)")
    df = df.Define("electrons_p", "FCCAnalyses::ReconstructedParticle::get_p(electrons)[0]")


    results.append(df.Histo1D(("muons_p", "", *bins_p_ll), "muons_p"))
    results.append(df.Histo1D(("electrons_p", "", *bins_p_ll), "electrons_p"))
    df = df.Define("muons_no", "FCCAnalyses::ReconstructedParticle::get_n(muons)")
    df = df.Define("electrons_no", "FCCAnalyses::ReconstructedParticle::get_n(electrons)")

    df = df.Filter("electrons_no <= 2")
    df = df.Filter("electrons_p < 20")
    df = df.Filter("muons_no <= 2")
    df = df.Filter("muons_p < 20")
    
    results.append(df.Histo1D(("electrons_no", "", *bins_count), "electrons_no"))

    results.append(df.Histo1D(("muons_no", "", *bins_count), "muons_no"))

    #df = df.Define("missingEnergy", "FCCAnalyses::ZHfunctions::missingEnergy(240., ReconstructedParticles)")
    #results.append(df.Histo1D(("missingEnergy", "", *bins_p_ll), "missingEnergy"))


  
  

    #df = df.Define("RPS_no_mu", "FCCAnalyses::ReconstructedParticle::remove(ReconstructedParticles, muons)")
   

    #Build Jets: 
    df= df.Define("RP_px", "FCCAnalyses::ReconstructedParticle::get_px(ReconstructedParticles)")
    df= df.Define("RP_py", "FCCAnalyses::ReconstructedParticle::get_py(ReconstructedParticles)")
    df= df.Define("RP_pz", "FCCAnalyses::ReconstructedParticle::get_pz(ReconstructedParticles)")
    df = df.Define("RP_e", "FCCAnalyses::ReconstructedParticle::get_e(ReconstructedParticles)")
    df = df.Define("pseudo_jets", "FCCAnalyses::JetClusteringUtils::set_pseudoJets(RP_px, RP_py, RP_pz, RP_e)")


    #Do Jet Clustering: 
    df = df.Define("clustered_jets", "JetClustering::clustering_ee_kt(3,6,0,10)(pseudo_jets)")

    df = df.Define("jets", "FCCAnalyses::JetClusteringUtils::get_pseudoJets(clustered_jets)")
    df = df.Define("jetconstituents", "FCCAnalyses::JetClusteringUtils::get_constituents(clustered_jets)") 
    df = df.Define("firstJet", "jetconstituents[0]")
    results.append(df.Histo1D(("jetconstituents", "", *bins_count), "firstJet"))
    df = df.Define("jets_e", "FCCAnalyses::JetClusteringUtils::get_e(jets)")
    df = df.Define("jets_px", "FCCAnalyses::JetClusteringUtils::get_px(jets)")
    df = df.Define("jets_py", "FCCAnalyses::JetClusteringUtils::get_py(jets)")
    df = df.Define("jets_pz", "FCCAnalyses::JetClusteringUtils::get_pz(jets)")
    df = df.Define("jets_phi", "FCCAnalyses::JetClusteringUtils::get_phi(jets)")
    df = df.Define("jets_pt", "FCCAnalyses::JetClusteringUtils::get_pt(jets)")
    df = df.Define("jets_m", "FCCAnalyses::JetClusteringUtils::get_m(jets)")
    
    #df = df.Filter("jets_pt > 20")
    

    # convert jets to LorentzVectors
    df = df.Define("jets_tlv", "FCCAnalyses::JHUfunctions::makeLorentzVectors(jets_px, jets_py, jets_pz, jets_e)")

    #attempting to do truth matching 
    df = df.Define("jets_truth", "FCCAnalyses::JHUfunctions::jetTruthFinder(jetconstituents, ReconstructedParticles, Particle, MCRecoAssociations1)") # returns best-matched PDG ID of the jets

    df = df.Define("RP_MC_index", "ReconstructedParticle2MC::getRP2MC_index(MCRecoAssociations0, MCRecoAssociations1, ReconstructedParticles)")
    results.append(df.Histo1D(("RP_MC_index", "", *bins_count), "RP_MC_index"))
   

    
    df = df.Define("Z_tlv", "FCCAnalyses::JHUfunctions::get_best_jet_pair(91.2, 125.0, 240, jets_tlv)")
    df = df.Define("Z_mass", "Z_tlv[0].M()")
    #df = df.Define("Z_mass", "(jets_tlv[0] + jets_tlv[1]).M()")
    df = df.Define("Z_pt","Z_tlv[0].Pt()" )
    df = df.Define("Jets_No", "jets_tlv.size()")
     
    #df = df.Filter("Z_pt < 61")
    # df = df.Define("zbuilder_result", f"FCCAnalyses::ZHfunctions::resonanceBuilder_mass_recoil(91.2, 125, 0.4, 240, {'true' if do_gen else 'false'})(jets, MCRecoAssociations0, MCRecoAssociations1, ReconstructedParticles, Particle, Particle0, Particle1)")
    # df = df.Define("zll", "ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>{zbuilder_result[0]}") # the Z
    # df = df.Define("zll_m", "FCCAnalyses::ReconstructedParticle::get_mass(zll)[0]")
    # df = df.Define("zll_recoil", "FCCAnalyses::ReconstructedParticle::recoilBuilder(240)(zll)")
    # df = df.Define("zll_recoil_m", "FCCAnalyses::ReconstructedParticle::get_mass(zll_recoil)[0]")



    #Make Histos 
    results.append(df.Histo1D(("Gen_cos_1", "", *bins_cos), "Gen_cos_1"))
    results.append(df.Histo1D(("Gen_cos_2", "", *bins_cos), "Gen_cos_2"))
    results.append(df.Histo1D(("Gen_phi", "", *bins_phiMELA), "Gen_phi"))

    results.append(df.Histo1D(("Gen_cos_1_BSM", "", *bins_cos), "Gen_cos_1", "BSMWeights"))
    results.append(df.Histo1D(("Gen_cos_2_BSM", "", *bins_cos), "Gen_cos_2", "BSMWeights"))
    results.append(df.Histo1D(("Gen_phi_BSM", "", *bins_phiMELA), "Gen_phi", "BSMWeights"))


    results.append(df.Histo1D(("Z_mass", "", *bins_m_Z), "Z_mass"))
    results.append(df.Histo1D(("Z_Mass_MC", "", *bins_m_Z), "Z_Mass_MC"))
    results.append(df.Histo1D(("Z_pt", "", *bins_p_ll), "Z_pt"))
    results.append(df.Histo1D(("Z_pt_MC", "", *bins_p_ll), "Z_pt_MC"))

    results.append(df.Histo1D(("jets_pt", "", *bins_p_ll), "jets_pt"))
    results.append(df.Histo1D(("Jets_No", "", *bins_count), "Jets_No"))

    # results.append(df.Histo1D(("full_decays", "", *bins_count), "full_decays"))
    # results.append(df.Histo1D(("full_decays_1", "", *bins_count), "full_decays_1"))
    # results.append(df.Histo1D(("full_decays_2", "", *bins_count), "full_decays_2"))
    # results.append(df.Histo1D(("full_decays_3", "", *bins_count), "full_decays_3"))

    # results.append(df.Histo1D(("zll_m", "", *bins_p_ll), "zll_m"))
    # results.append(df.Histo1D(("zll_m_recoil_m", "", *bins_p_ll), "zll_recoil_m"))

  
    results.append(df.Histo1D(("jets_truth", "", *bins_pdgid), "jets_truth"))
    #results.append(df.Histo1D(("HiggsIdx", "", *bins_count), "HiggsIdx[0]"))

    results.append(df.Histo1D(("daughter_higgs", "", *bins_pdgid), "daughter_higgs"))
    results.append(df.Histo1D(("daughter_higgs0", "", *bins_pdgid), "daughter_higgs0"))
    results.append(df.Histo1D(("HiggsIdx", "", *bins_count), "higgs_MC"))
    # results.append(df.Histo1D(("higgsE", "", *bins_p_mu), "higgsE"))

    
    results.append(df.Histo1D(("higgsParents", "", *bins_pdgid), "higgsParents"))
    # results.append(df.Histo1D(("higgsParent1", "", *bins_pdgid), "higgsParent_1"))
    # results.append(df.Histo1D(("higgsParent2", "", *bins_pdgid), "higgsParent_2"))
    results.append(df.Histo1D(("electronPDG", "", *bins_pdgid), "electronPDG"))
    results.append(df.Histo1D(("electronE", "", *bins_p_mu), "electronE"))
    results.append(df.Histo1D(("electronPz", "", *bins_p_mubeeg), "electronPz"))
    results.append(df.Histo1D(("electronDaus", "", *bins_pdgid), "electronDaus"))
    results.append(df.Histo1D(("electronDausIdx", "", *bins_pdgid), "electronDausIdx"))
    results.append(df.Histo1D(("electronGenStatus", "", *bins_count), "electronGenStatus"))
    results.append(df.Histo1D(("electronSimStatus", "", *bins_count), "electronSimStatus"))

    results.append(df.Histo1D(("positronPDG", "", *bins_pdgid), "positronPDG"))
    results.append(df.Histo1D(("positronE", "", *bins_p_mu), "positronE"))
    results.append(df.Histo1D(("positronPz", "", *bins_p_mubeeg), "positronPz"))
    results.append(df.Histo1D(("positronDaus", "", *bins_pdgid), "positronDaus"))
    results.append(df.Histo1D(("positronGenStatus", "", *bins_count), "positronGenStatus"))
    results.append(df.Histo1D(("positronSimStatus", "", *bins_count), "positronSimStatus"))

    results.append(df.Histo1D(("AllPDGs", "", *bins_pdgid), "AllPDGs"))

    results.append(df.Histo1D(("higgsPDG", "", *bins_pdgid), "higgsPDG"))
    results.append(df.Histo1D(("qBarPDG", "", *bins_pdgid), "qBarPDG"))
    results.append(df.Histo1D(("qBarE", "", *bins_p_mu), "qBarE"))

    results.append(df.Histo1D(("qPDG", "", *bins_pdgid), "qPDG"))
    results.append(df.Histo1D(("PDGTest", "", *bins_pdgid), "PDGTest"))
    results.append(df.Histo1D(("qE", "", *bins_p_mu), "qE"))



    # results.append(df.Histo1D(("full_decays_size", "", *bins_pdgid), "full_decays_size"))


    weightsum = df.Sum("nominal_weight")
    threading.Thread(target=print_process_id).start()
    return results, weightsum
threading.Thread(target=print_process_id).start()
    
