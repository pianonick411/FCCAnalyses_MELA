# analysis config
import ROOT 
flavor = "mumu" # mumu or ee
do_mass = True # for mass analysis, extra cut on cos(theta_miss)
do_gen = False # replace reco-particles by the corresponding gen particle
do_syst = False
do_weights = False


import os 
import threading 

def print_process_id(): 
    print(threading.current_thread, os.getpid())


# list of processes
processList = {
    # main backgrounds
 #  'p8_ee_WW_ecm240': {'fraction':1},
   'p8_ee_ZZ_ecm240': {'fraction':0.001},
 #  'wzp6_ee_tautau_ecm240': {'fraction':1},
 #  'wzp6_ee_mumu_ecm240' if flavor=="mumu" else 'wzp6_ee_ee_Mee_30_150_ecm240': {'fraction':1},

    #rare backgrounds
 #   f'wzp6_egamma_eZ_Z{flavor}_ecm240': {'fraction':1},
 #   f'wzp6_gammae_eZ_Z{flavor}_ecm240': {'fraction':1},
 #   f'wzp6_gaga_{flavor}_60_ecm240': {'fraction':1},
  #  'wzp6_gaga_tautau_60_ecm240': {'fraction':1},
  #  'wzp6_ee_nuenueZ_ecm240': {'fraction':1},
    
    # signal
 #  f'wzp6_ee_{flavor}H_ecm240': {'fraction':1},
}

#if do_mass:
#    processList[f'wzp6_ee_{flavor}H_mH-higher-100MeV_ecm240'] = {'fraction':1}
#    processList[f'wzp6_ee_{flavor}H_mH-higher-50MeV_ecm240'] = {'fraction':1}
#    processList[f'wzp6_ee_{flavor}H_mH-lower-100MeV_ecm240'] = {'fraction':1}
#    processList[f'wzp6_ee_{flavor}H_mH-lower-50MeV_ecm240'] = {'fraction':1}
#    if do_syst:
#        processList[f'wzp6_ee_{flavor}H_BES-higher-1pc_ecm240'] = {'fraction':1}
#        processList[f'wzp6_ee_{flavor}H_BES-lower-1pc_ecm240'] = {'fraction':1}

sigProcs = ["wzp6_ee_mumuH_ecm240", "wzp6_ee_eeH_ecm240"]
bkgProcs = ["p8_ee_WW_ecm240", "p8_ee_ZZ_ecm240", "wzp6_ee_tautau_ecm240", ""]


# Production tag when running over EDM4Hep centrally produced events, this points to the yaml files for getting sample statistics
prodTag     = "FCCee/winter2023/IDEA/"

# Link to the dictonary that contains all the cross section informations etc...
procDict = "FCCee_procDict_winter2023_IDEA.json"

# additional/custom C++ functions, defined in header files (optional)
includePaths = ["functions.h", "JHUfunctions.h"]


#Optional: output directory, default is local running directory
outputDir   = "FCCAnalysisOut/ZZComparison/"

#f"output_{flavor}/"


# optional: ncpus, default is 4, -1 uses all cores available
nCPUS       = -1

# scale the histograms with the cross-section and integrated luminosity
doScale = False
intLumi = 7200000 # 7.2 /ab



# define some binning for various histograms
bins_p_mu = (2000, 0, 200) # 100 MeV bins
bins_m_ll = (2000, 0, 200) # 100 MeV bins
bins_p_ll = (200, 0, 200) # 1 GeV bins
bins_recoil = (200, 120, 140) # 10 MeV bins 
bins_recoil_fine = (20000, 120, 140) # 1 MeV bins 
bins_cosThetaMiss = (10000, 0, 1)

bins_theta = (500, -5, 5)
bins_eta = (600, -3, 3)
bins_phi = (500, -5, 5)
bins_phiNP = (160, -3.2, 3.2)
bins_aco = (400, -4, 4)

bins_cos = (100, -1.0, 1.0)
bins_dis = (100, 0, 1.0)

bins_count = (80, 0, 80)
bins_charge = (10, -5, 5)
bins_iso = (500, 0, 5)
bins_cat = (10, 0, 10)
bins_resolution = (10000, 0.95, 1.05)
bins_phiRW = (20, 0, 20)

bins_weight = (100, -2, 2)
bins_weird = (1000, -500, 500)




# build_graph function that contains the analysis logic, cuts and histograms (mandatory)
def build_graph(df, dataset):

    print("build graph", dataset)
    print_process_id()
    results = []
  
    

    df = df.Alias("Particle0", "Particle#0.index")
    df = df.Alias("Particle1", "Particle#1.index")
    df = df.Alias("MCRecoAssociations0", "MCRecoAssociations#0.index")
    df = df.Alias("MCRecoAssociations1", "MCRecoAssociations#1.index")
    df = df.Alias("Photon0", "Photon#0.index")
    if flavor == "mumu":
        df = df.Alias("Lepton0", "Muon#0.index")
    else:
        df = df.Alias("Lepton0", "Electron#0.index")
    
    df = df.Define("LHEAssociatedParticleId", "FCCAnalyses::JHUfunctions::SetAssocId(13, -13)")
    
    
    df = df.Define("LHEDaughterId", "FCCAnalyses::JHUfunctions::SetHiggsId()")

    df = df.Define("ghz1Pair", 'FCCAnalyses::JHUfunctions::makeCouplingPairs("ghz1", 2, 0)')
    df = df.Define("SMVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz1Pair})')


    df = df.Define("EqualMixghz4Pair", 'FCCAnalyses::JHUfunctions::makeCouplingPairs("ghz4", 0.864922411, 0)')
    df = df.Define("NegEqualMixghz4Pair", 'FCCAnalyses::JHUfunctions::makeCouplingPairs("ghz4", -0.864922411, 0)')
    df = df.Define("EqualBSMVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({EqualMixghz4Pair})')
    df = df.Define("EqualMixtureVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz1Pair, EqualMixghz4Pair})')
    df = df.Define("NegEqualMixtureVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz1Pair, NegEqualMixghz4Pair})')


    df = df.Define("ghz4Pair", 'FCCAnalyses::JHUfunctions::makeCouplingPairs("ghz4", 1.0, 0)')
    df = df.Define("Negghz4Pair", 'FCCAnalyses::JHUfunctions::makeCouplingPairs("ghz4", -1.0, 0)')
    df = df.Define("BSMVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz4Pair})')
    df = df.Define("MixtureVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz1Pair, ghz4Pair})')
    df = df.Define("NegMixtureVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz1Pair, Negghz4Pair})')


    if dataset in sigProcs: 
        df = df.Define("full_decays", "FCCAnalyses::MCParticle::get_indices(11, FCCAnalyses::JHUfunctions::DesiredDaughters(), false, true, false, true)(Particle, Particle1)")
        df = df.Define("positron_decays", "FCCAnalyses::MCParticle::get_indices(-11, FCCAnalyses::JHUfunctions::DesiredDaughters(), false, true, false, true)(Particle, Particle1)")
        df = df.Define("electronMC", "FCCAnalyses::MCParticle::sel_byIndex(full_decays[0], Particle)")
        df = df.Define("electronVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{electronMC}")
        df = df.Define("electronGenStatus", "FCCAnalyses::MCParticle::get_genStatus(electronVec_MC)")
        df = df.Define("electronSimStatus", "FCCAnalyses::MCParticle::get_simStatus(electronVec_MC)")
        df = df.Define("electronTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(electronVec_MC)")

   # df = df.Define("positronMC", "FCCAnalyses::MCParticle::sel_byIndex(positron_decays[0], Particle)")
        df = df.Define("positronMC", "FCCAnalyses::MCParticle::sel_byIndex(05, Particle)")
        df = df.Define("positronVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{positronMC}")
        df = df.Define("positronGenStatus", "FCCAnalyses::MCParticle::get_genStatus(positronVec_MC)")
        df = df.Define("positronSimStatus", "FCCAnalyses::MCParticle::get_simStatus(positronVec_MC)")
        df = df.Define("positronTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(positronVec_MC)")
            
        df = df.Define("negmuMC", "FCCAnalyses::MCParticle::sel_byIndex(full_decays[1], Particle)") 
        df = df.Define("negmuVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{negmuMC}")
        df = df.Define("negmuGenStatus", "FCCAnalyses::MCParticle::get_genStatus(negmuVec_MC)")
        df = df.Define("negmuSimStatus", "FCCAnalyses::MCParticle::get_simStatus(negmuVec_MC)")
        df = df.Define("negmuTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(negmuVec_MC)")

        df = df.Define("posmuMC", "FCCAnalyses::MCParticle::sel_byIndex(full_decays[2], Particle)") 
        df = df.Define("posmuVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{posmuMC}")
        df = df.Define("posmuGenStatus", "FCCAnalyses::MCParticle::get_genStatus(posmuVec_MC)")
        df = df.Define("posmuSimStatus", "FCCAnalyses::MCParticle::get_simStatus(posmuVec_MC)")
        df = df.Define("posmuTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(posmuVec_MC)")

        df = df.Define("higgsMC", "FCCAnalyses::MCParticle::sel_byIndex(full_decays[3], Particle)")
        df = df.Define("higgsVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{higgsMC}")
        df = df.Define("higgsGenStatus", "FCCAnalyses::MCParticle::get_genStatus(higgsVec_MC)")
        df = df.Define("higgsSimStatus", "FCCAnalyses::MCParticle::get_simStatus(higgsVec_MC)")
        df = df.Define("higgsMCTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(higgsVec_MC)")
    
    if do_weights:
        df = df.Define("SMWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, negmuTLV, posmuTLV, SMVec)')
        df = df.Define("BSMWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, negmuTLV, posmuTLV, BSMVec)')
        df = df.Define("BSMWeightsEqual", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, negmuTLV, posmuTLV, EqualBSMVec)')

        df = df.Define("MixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, negmuTLV, posmuTLV, MixtureVec)')
        df = df.Define("NegMixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, negmuTLV, posmuTLV, NegMixtureVec)')
    
        df = df.Define("EqualMixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, negmuTLV, posmuTLV, EqualMixtureVec)')
        df = df.Define("NegEqualMixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, negmuTLV, posmuTLV, NegEqualMixtureVec)')

        df = df.Define("EqualInterferenceWeights", 'EqualMixtureWeights - BSMWeightsEqual - SMWeights')
        df = df.Define("NegEqualInterferenceWeights", 'NegEqualMixtureWeights - BSMWeightsEqual - SMWeights')

        df = df.Define("InterferenceWeights", 'MixtureWeights - BSMWeights - SMWeights')
        df = df.Define("NegInterferenceWeights", 'NegMixtureWeights - BSMWeights- SMWeights')
   
    # define cutflow variables
    for i in range(0, 20):
        df = df.Define("cut%d"%i, "%d"%i)

    df = df.Define("nominal_weight", "1.0")

    # all leptons (bare)
    df = df.Define("leps_all", "FCCAnalyses::ReconstructedParticle::get(Lepton0, ReconstructedParticles)")
    df = df.Define("leps_all_p", "FCCAnalyses::ReconstructedParticle::get_p(leps_all)")
    df = df.Define("leps_all_theta", "FCCAnalyses::ReconstructedParticle::get_theta(leps_all)")
    df = df.Define("leps_all_phi", "FCCAnalyses::ReconstructedParticle::get_phi(leps_all)")
    df = df.Define("leps_all_q", "FCCAnalyses::ReconstructedParticle::get_charge(leps_all)")
    df = df.Define("leps_all_no", "FCCAnalyses::ReconstructedParticle::get_n(leps_all)")
    df = df.Define("leps_all_iso", "FCCAnalyses::ZHfunctions::coneIsolation(0.01, 0.5)(leps_all, ReconstructedParticles)")

    # cuts on leptons
    df = df.Define("leps", "FCCAnalyses::ReconstructedParticle::sel_p(20)(leps_all)")
    df = df.Define("leps_p", "FCCAnalyses::ReconstructedParticle::get_p(leps)")
    df = df.Define("leps_theta", "FCCAnalyses::ReconstructedParticle::get_theta(leps)")
    df = df.Define("leps_phi", "FCCAnalyses::ReconstructedParticle::get_phi(leps)")
    df = df.Define("leps_q", "FCCAnalyses::ReconstructedParticle::get_charge(leps)")
    df = df.Define("leps_no", "FCCAnalyses::ReconstructedParticle::get_n(leps)")
    df = df.Define("leps_iso", "FCCAnalyses::ZHfunctions::coneIsolation(0.01, 0.5)(leps, ReconstructedParticles)")
    df = df.Define("leps_sel_iso", "FCCAnalyses::ZHfunctions::sel_iso(0.25)(leps, leps_iso)")

    # momentum resolution
    df = df.Define("leps_all_reso_p", "FCCAnalyses::ZHfunctions::leptonResolution_p(leps_all, MCRecoAssociations0, MCRecoAssociations1, ReconstructedParticles, Particle)")
    df = df.Define("leps_reso_p", "FCCAnalyses::ZHfunctions::leptonResolution_p(leps, MCRecoAssociations0, MCRecoAssociations1, ReconstructedParticles, Particle)")

    # gen analysis
    if dataset in sigProcs:
        df = df.Define("higgs_MC", "FCCAnalyses::ZHfunctions::sel_pdgID_idx(25,false)(Particle)")
        df = df.Define("daughter_higgs", "FCCAnalyses::ZHfunctions::gen_decay_list(higgs_MC, Particle, Particle1)")
        df = df.Define("daughter_higgs_collapsed", "daughter_higgs.size()>1 ? ((abs(daughter_higgs[0])+abs(daughter_higgs[1]))*0.5) : -1000")

    # baseline selections and histograms
    results.append(df.Histo1D(("leps_all_p_presel", "", *bins_p_mu), "leps_all_p", "nominal_weight"))
    results.append(df.Histo1D(("leps_all_theta_presel", "", *bins_theta), "leps_all_theta", "nominal_weight"))
    results.append(df.Histo1D(("leps_all_no_presel", "", *bins_count), "leps_all_no", "nominal_weight"))
    results.append(df.Histo1D(("leps_all_iso_presel", "", *bins_iso), "leps_all_iso", "nominal_weight"))
    results.append(df.Histo1D(("leps_all_reso_p_presel", "", *bins_resolution), "leps_all_reso_p", "nominal_weight"))

    results.append(df.Histo1D(("leps_p_presel", "", *bins_p_mu), "leps_p", "nominal_weight"))
    results.append(df.Histo1D(("leps_theta_presel", "", *bins_theta), "leps_theta", "nominal_weight"))
    results.append(df.Histo1D(("leps_no_presel", "", *bins_count), "leps_no", "nominal_weight"))
    results.append(df.Histo1D(("leps_iso_presel", "", *bins_iso), "leps_iso"))
    results.append(df.Histo1D(("leps_reso_p_presel", "", *bins_resolution), "leps_reso_p", "nominal_weight"))
    

    if dataset in sigProcs: 
        results.append(df.Histo1D(("higgs_decay_cut0", "", *bins_count), "daughter_higgs_collapsed", "nominal_weight"))

    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut0", "nominal_weight"))

    #########
    ### CUT 1: at least a lepton with at least 1 isolated one
    #########
    df = df.Filter("leps_no >= 1 && leps_sel_iso.size() > 0")
    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut1", "nominal_weight"))
    if dataset in sigProcs: 
        results.append(df.Histo1D(("higgs_decay_cut1", "", *bins_count), "daughter_higgs_collapsed", "nominal_weight"))

    #########
    ### CUT 2 :at least 2 OS leptons, and build the resonance
    #########
    df = df.Filter("leps_no >= 2 && abs(Sum(leps_q)) < leps_q.size()")
    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut2", "nominal_weight"))


    # build the Z resonance based on the available leptons. Returns the best lepton pair compatible with the Z mass and recoil at 125 GeV
    # technically, it returns a ReconstructedParticleData object with index 0 the di-lepton system, index and 2 the leptons of the pair
    df = df.Define("zbuilder_result", f"FCCAnalyses::ZHfunctions::resonanceBuilder_mass_recoil(91.2, 125, 0.4, 240, {'true' if do_gen else 'false'})(leps, MCRecoAssociations0, MCRecoAssociations1, ReconstructedParticles, Particle, Particle0, Particle1)")
    df = df.Define("zll", "ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>{zbuilder_result[0]}") # the Z
    df = df.Define("zll_leps", "ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>{zbuilder_result[1],zbuilder_result[2]}") # the leptons
    df = df.Define("zll_leps_pos", "FCCAnalyses::ReconstructedParticle::sel_charge(1, false)(zll_leps)")
    df = df.Define("zll_leps_neg", "FCCAnalyses::ReconstructedParticle::sel_charge(-1, false)(zll_leps)")
    df = df.Define("zll_lep1", "ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>{zbuilder_result[1]}")
    df = df.Define("zll_lep1_q", "FCCAnalyses::ReconstructedParticle::get_charge(zll_lep1)")
    df = df.Define("zll_lep2", "ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>{zbuilder_result[2]}")
    df = df.Define("zll_lep2_q", "FCCAnalyses::ReconstructedParticle::get_charge(zll_lep2)")
    df = df.Define("zll_m", "FCCAnalyses::ReconstructedParticle::get_mass(zll)[0]")
    df = df.Define("zll_p", "FCCAnalyses::ReconstructedParticle::get_p(zll)[0]")
    df = df.Define("zll_px", "FCCAnalyses::ReconstructedParticle::get_px(zll)[0]")
    df = df.Define("zll_py", "FCCAnalyses::ReconstructedParticle::get_py(zll)[0]")
    df = df.Define("zll_pz", "FCCAnalyses::ReconstructedParticle::get_pz(zll)[0]")
    df = df.Define("zll_recoil", "FCCAnalyses::ReconstructedParticle::recoilBuilder(240)(zll)")
    df = df.Define("zll_recoil_m", "FCCAnalyses::ReconstructedParticle::get_mass(zll_recoil)[0]")
    df = df.Define("zll_category", "FCCAnalyses::ZHfunctions::polarAngleCategorization(0.8, 2.34)(zll_leps)")

    df = df.Define("zll_leps_p", "FCCAnalyses::ReconstructedParticle::get_p(zll_leps)")
    df = df.Define("zll_leps_theta", "FCCAnalyses::ReconstructedParticle::get_theta(zll_leps)")

    df = df.Define("missingEnergy", "FCCAnalyses::ZHfunctions::missingEnergy(240., ReconstructedParticles)")
    df = df.Define("cosTheta_miss", "FCCAnalyses::ZHfunctions::get_cosTheta_miss(missingEnergy)")

    df = df.Define("acoplanarity", "FCCAnalyses::ZHfunctions::acoplanarity(leps)")
    df = df.Define("acolinearity", "FCCAnalyses::ZHfunctions::acolinearity(leps)")
    

    
    #TLVs for angular analysis 
    df = df.Define("higgs_tlv", "FCCAnalyses::JHUfunctions::makeLorentzVectors(zll_recoil)")  # this is a vector containing 1 Lorentzvector, i.e. the Higgs
    df = df.Define("z_tlv", "FCCAnalyses::JHUfunctions::makeLorentzVectors(zll)") #this is a vector containing 1 Lorentzvector, i.e. the associated Z. 
    df = df.Define("zStar_tlv", "FCCAnalyses::JHUfunctions::VecSum(z_tlv, higgs_tlv)") #this is a vector containg 1 Lorentzvector, i.e. the offshell Z-propagator
    df = df.Define("leps_pos_tlv", "FCCAnalyses::JHUfunctions::makeLorentzVectors(zll_leps_pos)") #this is a vector containing the positive leptons coming from the associated Z
    df = df.Define("leps_neg_tlv", "FCCAnalyses::JHUfunctions::makeLorentzVectors(zll_leps_neg)") #this is a vector containing the negative leptons coming from the associated Z

    #TLVs for angular analysis that come from GEN-LEVEL data, i.e. the incoming e+e- pair. 
    # Construct fixed LV where you only have half beam energy for each 
   # df = df.Define("positron_mc", "FCCAnalyses::MCParticle::sel_pdgID(-11, false)(Particle)")
   # df = df.Define("positron_tlv", "FCCAnalyses::JHUfunctions::makeLorentzVectors(positron_mc)")

   # df = df.Define("electron_mc", "FCCAnalyses::MCParticle::sel_pdgID(11, false)(Particle)")
   # df = df.Define("electron_tlv", "FCCAnalyses::JHUfunctions::makeLorentzVectors(electron_mc)")
    
    df = df.Define("positron_tlv", "FCCAnalyses::JHUfunctions::makePositronTlv()")
    df = df.Define("electron_tlv", "FCCAnalyses::JHUfunctions::makeElectronTlv()")
    
    

    #df = df.Define("cos_1", "FCCAnalyses::JHUfunctions::CosineTheta1(z_tlv, zStar_tlv, leps_neg_tlv)")
    #df = df.Define("cos_2", "FCCAnalyses::JHUfunctions::CosineTheta2(z_tlv, zStar_tlv, positron_tlv)")
    #df = df.Define("phi", "FCCAnalyses::JHUfunctions::AnglePhi(higgs_tlv, z_tlv, leps_neg_tlv, leps_pos_tlv, positron_tlv, electron_tlv)")

    df = df.Define("MELA_Angles", "FCCAnalyses::JHUfunctions::MELAAngles(electron_tlv, 11, positron_tlv, -11, leps_neg_tlv, 13, leps_pos_tlv, -13)")

    df = df.Define("cos_1", "MELA_Angles[1]")
    df = df.Define("cos_2", "MELA_Angles[2]")
    df = df.Define("phi", "MELA_Angles[3]")
    df = df.Define("mVstar", "MELA_Angles[5]")
    df = df.Define("mV", "MELA_Angles[6]")
    
    

    #Columns for the purpose of exporting to MELA 

    """ LHEAssociatedParticleId = array("f", [0,0])
    LHEAssociatedParticlePt = array("f", [0,0])
    LHEAssociatedParticleEta = array("f", [0,0])
    LHEAssociatedParticlePhi = array("f", [0,0])
    LHEAssociatedParticleMass = array("f", [0,0])

    LHEDaughterId = array("f", [0,0])
    LHEDaughterPt = array("f", [0,0])
    LHEDaughterEta = array("f", [0,0])
    LHEDaughterPhi = array("f", [0,0])
    LHEDaughterMass = array("f", [0,0])"""
    
    df = df.Define("LHEAssociatedParticlePt", "FCCAnalyses::JHUfunctions::SetAssocPt(leps_neg_tlv, leps_pos_tlv)")
    df = df.Define("LHEAssociatedParticleEta", "FCCAnalyses::JHUfunctions::SetAssocEta(leps_neg_tlv, leps_pos_tlv)")
    df = df.Define("LHEAssociatedParticlePhi", "FCCAnalyses::JHUfunctions::SetAssocPhi(leps_neg_tlv, leps_pos_tlv)")
    df = df.Define("LHEAssociatedParticleMass", "FCCAnalyses::JHUfunctions::SetAssocM(leps_neg_tlv, leps_pos_tlv)")

    df = df.Define("LHEDaughterPt", "FCCAnalyses::JHUfunctions::SetHiggsPt(higgs_tlv)")
    df = df.Define("LHEDaughterEta", "FCCAnalyses::JHUfunctions::SetHiggsEta(higgs_tlv)")
    df = df.Define("LHEDaughterPhi", "FCCAnalyses::JHUfunctions::SetHiggsPhi(higgs_tlv)")
    df = df.Define("LHEDaughterMass","FCCAnalyses::JHUfunctions::SetHiggsM(higgs_tlv)")


    

    

    if dataset in sigProcs:
        results.append(df.Histo1D(("higgs_decay_cut2", "", *bins_count), "daughter_higgs_collapsed", "nominal_weight"))

    #########
    ### CUT 3: Z mass window
    #########
    results.append(df.Histo1D(("Z_Mass_nmone", "", *bins_m_ll), "zll_m", "nominal_weight"))
    df = df.Filter("zll_m > 86 && zll_m < 96")
    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut3"))
    
    if dataset in sigProcs:
        results.append(df.Histo1D(("higgs_decay_cut3", "", *bins_count), "daughter_higgs_collapsed", "nominal_weight"))

    #########
    ### CUT 4: Z momentum
    #########
    results.append(df.Histo1D(("Z_p_nmone", "", *bins_p_mu), "zll_p"))
    df = df.Filter("zll_p > 45 && zll_p < 55")
    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut4", "nominal_weight"))
    results.append(df.Histo1D(("zll_recoil_cut4", "", *bins_recoil), "zll_recoil_m", "nominal_weight"))
    if dataset in sigProcs:
        results.append(df.Histo1D(("higgs_decay_cut4", "", *bins_count), "daughter_higgs_collapsed", "nominal_weight"))

    #########
    ### CUT 5: recoil cut
    #########
    results.append(df.Histo1D(("recoil_mass_nmone", "", *bins_recoil), "zll_recoil_m", "nominal_weight"))
    df = df.Filter("zll_recoil_m < 127 && zll_recoil_m > 124")
    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut5", "nominal_weight"))
    results.append(df.Histo1D(("cosThetaMiss_cut5", "", *bins_cosThetaMiss), "cosTheta_miss", "nominal_weight"))
    if dataset in sigProcs: 
        results.append(df.Histo1D(("higgs_decay_cut5", "", *bins_count), "daughter_higgs_collapsed", "nominal_weight"))

    #########
    ### CUT 6: cosThetaMiss, only for mass analysis
    #########
    results.append(df.Histo1D(("cosThetaMiss_nmone", "", *bins_cosThetaMiss), "cosTheta_miss", "nominal_weight"))
    if do_mass:
        df = df.Filter("cosTheta_miss < 0.98")
    if dataset in sigProcs: 
        results.append(df.Histo1D(("higgs_decay_cut6", "", *bins_count), "daughter_higgs_collapsed", "nominal_weight"))
    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut6"))

    #########
    ### CUT 7: cos1: 
    #########
    results.append(df.Histo1D(("cos_2_nmone", "", *bins_cos), "cos_2", "nominal_weight"))
    df = df.Filter("cos_2 < 0.99 && cos_2 > -0.99")
    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut7", "nominal_weight"))
    if dataset in sigProcs: 
        results.append(df.Histo1D(("higgs_decay_cut7", "", *bins_count), "daughter_higgs_collapsed", "nominal_weight"))
    

    
    
    
 
    

    
   # df = df.Define("whatever", "FCCAnalyses::JHUfunctions::yeah(1)")

    

    #if dataset in sigProcs: 
    


        #df = df.Define("parents_MC", "FCCAnalyses::MCParticle::get_parentid(higgs_MC, Particle, Particle0)")
        #df = df.Define("higgs_gen_tlv", "FCCAnalyses::MCParticle::get_tlv(Particle[higgs_MC])")
        

       # df = df.Define("yeah", "FCCAnalyses::JHUfunctions::yeah(positronTLV)")
       # df = df.Define("pain", "FCCAnalyses::JHUfunctions::gen_list(full_decays, Particle)")
       # df = df.Define("electron_gen_tlv", "FCCAnalyses::MCParticle::get_tlv(Particle[full_decays.at(0)])")
       # df = df.Define("electronSanity", "FCCAnalyses::JHUfunctions::tlvSanity(electron_gen_tlv)")
        
       # df = df.Define("parents_PDG", "FCCAnalyses::JHUfunctions::gen_list(parents_MC, Particle)")
       # df = df.Define("parent1pdg", "FCCAnalyses::JHUfunctions::parent1pdg(parents_PDG[0])")
       # df = df.Define("parents_decay_list", "FCCAnalyses::ZHfunctions::gen_decay_list(parents_MC, Particle, Particle1)")
    
    if do_weights:
        df = df.Define("RecoSMWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgs_tlv, LHEAssociatedParticleId, leps_neg_tlv, leps_pos_tlv, SMVec)')
        df = df.Define("RecoBSMWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgs_tlv, LHEAssociatedParticleId, leps_neg_tlv, leps_pos_tlv, BSMVec)')


        df = df.Define("RecoBSMWeightsEqual", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgs_tlv, LHEAssociatedParticleId, leps_neg_tlv, leps_pos_tlv, EqualBSMVec)')

        df = df.Define("RecoMixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgs_tlv, LHEAssociatedParticleId, leps_neg_tlv, leps_pos_tlv, MixtureVec)')
        df = df.Define("RecoNegMixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgs_tlv, LHEAssociatedParticleId, leps_neg_tlv, leps_pos_tlv, NegMixtureVec)')
        df = df.Define("RecoInterferenceWeights", 'RecoMixtureWeights - RecoSMWeights - RecoBSMWeights')
        
        df = df.Define("RecoEqualMixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgs_tlv, LHEAssociatedParticleId, leps_neg_tlv, leps_pos_tlv, EqualMixtureVec)')
        df = df.Define("RecoNegEqualMixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgs_tlv, LHEAssociatedParticleId, leps_neg_tlv, leps_pos_tlv, NegEqualMixtureVec)')
        df = df.Define("RecoEqualInterferenceWeights", 'RecoEqualMixtureWeights - RecoSMWeights - RecoBSMWeightsEqual')
        df = df.Define("RecoNegEqualInterferenceWeights", 'RecoNegEqualMixtureWeights - RecoSMWeights - RecoBSMWeightsEqual')

        df = df.Define("D_0Minus", 'RecoSMWeights/ (RecoSMWeights + RecoBSMWeights)')
        df = df.Define("D_CP", 'RecoInterferenceWeights/(2*sqrt(RecoSMWeights*RecoBSMWeights))')
        

        df = df.Define("D_0Minus_Equal", 'RecoSMWeights/ (RecoSMWeights + RecoBSMWeightsEqual)')
        df = df.Define("D_CP_Equal", 'RecoEqualInterferenceWeights/(2*sqrt(RecoSMWeights*RecoBSMWeightsEqual))')
    

    # df = df.Define("RecoSMWeightsNORM", 'RecoSMWeights/RecoSMWeights')
    # df = df.Define("RecoSMWeightsINV", '1/RecoSMWeights')
    # df = df.Define("RecoBSMWeightsNORM", 'RecoBSMWeights/RecoSMWeights')
    # df = df.Define("RecoBSMWeightsEqualXSNORM", 'RecoBSMWeightsEqualXS/RecoSMWeights')
    # df = df.Define("RecoMixtureWeightsNORM", 'RecoMixtureWeights/(2*RecoSMWeights)')
    # df = df.Define("RecoNegMixtureWeightsNORM", 'RecoNegMixtureWeights/(2*RecoSMWeights)')
    # df = df.Define("RecoInterferenceWeightsNORM", 'RecoInterferenceWeights/RecoSMWeights')
    # df = df.Define("D_0MinusNORM", 'RecoSMWeightsNORM/(RecoSMWeightsNORM + RecoBSMWeightsNORM)')
    # df = df.Define("D_CPNORM", 'RecoInterferenceWeightsNORM/(2*sqrt(RecoSMWeightsNORM*RecoBSMWeightsNORM))')

    # df = df.Define("SMWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, negmuTLV, posmuTLV, SMVec)')
    # df = df.Define("BSMWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, negmuTLV, posmuTLV, BSMVec)')
    # df = df.Define("MixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, negmuTLV, posmuTLV, MixtureVec)')
    # df = df.Define("NegMixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, negmuTLV, posmuTLV, NegMixtureVec)')
    if dataset in sigProcs: 
        if do_weights:
            df = df.Define("SMWeightsNORM", "SMWeights/SMWeights")
            df = df.Define("BSMWeightsNORM", 'BSMWeights/SMWeights')
            df = df.Define("BSMWeightsEqualNORM", 'BSMWeightsEqual/SMWeights')
            df = df.Define("MixtureWeightsNORM", 'MixtureWeights/SMWeights')
            df = df.Define("NegMixtureWeightsNORM", 'NegMixtureWeights/SMWeights')    
            df = df.Define("InterferenceWeightsNORM", "InterferenceWeights/SMWeights")
            
            df = df.Define("EqualMixtureWeightsNORM", "EqualMixtureWeights/SMWeights")
            df = df.Define("NegEqualMixtureWeightsNORM", "NegEqualMixtureWeights/SMWeights")
            df = df.Define("EqualInterferenceWeightsNORM", "EqualInterferenceWeights/SMWeights")
        
    weightsum = df.Sum("nominal_weight")
   # ROOT.gInterpreter.Declare('float weight = float(TPython::Exec("weightsum"));') #This approach doesn't work. FCC Framework won't accept python callables even defined this way. Probably because these variables are never truly global. 



    # final histograms
   #results.append(df.Histo1D(("parent1pdg", "", *bins_count), "parent1pdg", "nominal_weight"))
    results.append(df.Histo1D(("leps_p", "", *bins_p_mu), "leps_p", "nominal_weight"))
    results.append(df.Histo1D(("Z_p", "", *bins_p_mu), "zll_p", "nominal_weight"))
    results.append(df.Histo1D(("Z_mass", "", *bins_m_ll), "zll_m", "nominal_weight"))
    results.append(df.Histo1D(("recoil_mass", "", *bins_recoil), "zll_recoil_m", "nominal_weight"))

    results.append(df.Histo1D(("cos_1", "", *bins_cos), "cos_1", "nominal_weight"))
    results.append(df.Histo1D(("cos_1_no_weight", "", *bins_cos), "cos_1"))
    
    results.append(df.Histo1D(("cos_2", "", *bins_cos), "cos_2", "nominal_weight"))
   
    results.append(df.Histo1D(("phi", "", *bins_phiNP), "phi", "nominal_weight"))
    results.append(df.Histo1D(("mVstar", "", *bins_recoil), "mVstar", "nominal_weight"))
    results.append(df.Histo1D(("mV", "", *bins_recoil), "mV", "nominal_weight"))



    # #Defining the phi histos scaled to nreco: 
    # if "ZZ" in dataset: 
    #     df = df.Define("ZZScale", "7200*ZZxs/weight")
    #     results.append(df.Histo1D(("phi_ZZ", "", *bins_phiNP), "phi", "ZZScale"))
    #     results.append(df.HistoND(("Combine_Input", "", 4, *(bins_cos + bins_cos + bins_phiNP + bins_weight)), "cos_1", "cos_2", "phi", "ZZScale"))
    # if "WW" in dataset:
    #     df = df.Define("WWScale", "7200*WWxs/weight")
    #     results.append(df.Histo1D(("phi_WW", "", *bins_phiNP), "phi", "WWScale"))
    #     results.append(df.HistoND(("Combine_Input", "", 4, *(bins_cos + bins_cos + bins_phiNP + bins_weight)), "cos_1", "cos_2", "phi", "WWScale"))
    # if "mumu_" in dataset:
    #     df = df.Define("mumuScale", "7200*mumuxs/weight")
    #     results.append(df.Histo1D(("phi_mumu", "", *bins_phiNP), "phi", "mumuScale"))
    #     results.append(df.HistoND(("Combine_Input", "", 4, *(bins_cos + bins_cos + bins_phiNP + bins_weight)), "cos_1", "cos_2", "phi", "mumuScale"))
        
    # if "tautau" in dataset:
    #     df = df.Define("tautauScale", "7200*tautauxs/weight")
    #     results.append(df.Histo1D(("phi_tautau", "", *bins_phiNP), "phi", "tautauScale"))
    #     results.append(df.HistoND(("Combine_Input", "", 4, *(bins_cos + bins_cos + bins_phiNP + bins_weight)), "cos_1", "cos_2", "phi", "tautauScale"))
        
    # if "egamma" in dataset:
    #     df = df.Define("egammaScale", "7200*egammaxs/weight")
    #     results.append(df.Histo1D(("phi_egamma", "", *bins_phiNP), "phi", "egammaScale"))
    #     results.append(df.HistoND(("Combine_Input", "", 4, *(bins_cos + bins_cos + bins_phiNP + bins_weight)), "cos_1", "cos_2", "phi", "egammaScale"))
        
    # if "gammae" in dataset:
    #     df = df.Define("gammaeScale", "7200*gammaexs/weight")
    #     results.append(df.Histo1D(("phi_gammae", "", *bins_phiNP), "phi", "gammaeScale"))
    #     results.append(df.HistoND(("Combine_Input", "", 4, *(bins_cos + bins_cos + bins_phiNP + bins_weight)), "cos_1", "cos_2", "phi", "gammaeScale"))
        
    # if "gagatautau" in dataset:
    #     df = df.Define("gagatautauScale", "7200*gagatautauxs/weight")
    #     results.append(df.Histo1D(("phi_gagatautau", "", *bins_phiNP), "phi", "gagatautauScale"))
    #     results.append(df.Histo3D(("3DCombine_Input", "", *(bins_cos + bins_cos + bins_phiNP + bins_weight)), "cos_1", "cos_2", "phi", "gagatautauScale"))
    #     results.append(df.HistoND(("Combine_Input", "", 4, *(bins_cos + bins_cos + bins_phiNP + bins_weight)), "cos_1", "cos_2", "phi", "gagatautauScale"))
        
    # if "gagamumu" in dataset:
    #     df = df.Define("gagamumuScale", "7200*gagamumuxs/weight")
    #     results.append(df.Histo1D(("phi_gagamumu", "", *bins_phiNP), "phi", "gagamumuScale"))
    #     results.append(df.HistoND(("Combine_Input", "", 4, *(bins_cos + bins_cos + bins_phiNP + bins_weight)), "cos_1", "cos_2", "phi", "gagamumuScale"))
        
    # if "nu" in dataset:
    #     df = df.Define("nuEntries", "FCCAnalyses::JHUfunctions::NumOfEntries(cos_1)")
    #     df = df.Define("nuXS", "7200*33.27*2694/2000000")
    #     df = df.Define("nuScale", "nuXS/nuEntries")
    #     results.append(df.Histo1D(("phi_nu", "", *bins_phiNP), "phi", "nuScale"))
    #     df.Define("ScaledPhiNu", "ROOT")
    #     model = ROOT.RDF.THnDModel("Combine_Input4d", "", 4, )
    #     results.append(df.Histo3D(("Combine_Input", "", *(bins_cos + bins_cos + bins_phiRW)), "cos_1", "cos_2", "phi", "nuScale"))
    #     results.append(df.HistoND(("Combine_Input4D", "", 4, *(bins_cos + bins_cos + bins_phiNP + bins_weight)), ["cos_1", "cos_2", "phi", "nuScale"]))
        
    
    
    
    
    

    


    
    

    

    

    results.append(df.Histo1D(("cosThetaMiss", "", *bins_cosThetaMiss), "cosTheta_miss", "nominal_weight"))
    results.append(df.Histo1D(("acoplanarity", "", *bins_aco), "acoplanarity", "nominal_weight"))
    results.append(df.Histo1D(("acolinearity", "", *bins_aco), "acolinearity", "nominal_weight"))

    results.append(df.Histo1D(("zll_lep1_q", "", *bins_charge), "zll_lep1_q", "nominal_weight"))
    results.append(df.Histo1D(("zll_lep2_q", "", *bins_charge), "zll_lep2_q", "nominal_weight"))

    results.append(df.Histo2D(("zll_recoil_m_cat", "", *(bins_recoil_fine + bins_cat)), "zll_recoil_m", "zll_category", "nominal_weight"))


    


    #if dataset in sigProcs:
    if do_weights:
        results.append(df.Histo1D(("RecoSMWeights", "", *bins_weight), "RecoSMWeights", "nominal_weight"))
        results.append(df.Histo1D(("RecoBSMWeights", "", *bins_weight), "RecoBSMWeights", "nominal_weight"))
        results.append(df.Histo1D(("RecoBSMWeightsEqual", "", *bins_weight), "RecoBSMWeightsEqual", "nominal_weight"))
        results.append(df.Histo1D(("RecoMixtureWeights", "", *bins_weight), "RecoMixtureWeights", "nominal_weight"))
        results.append(df.Histo1D(("RecoNegMixtureWeights", "", *bins_weight), "RecoNegMixtureWeights", "nominal_weight"))
        results.append(df.Histo1D(("RecoInterferenceWeights", "", *bins_weight), "RecoInterferenceWeights", "nominal_weight"))
    # results.append(df.Histo1D(("RecoNegInterferenceWeights", "", *bins_weight), "RecoNegInterferenceWeights", "nominal_weight"))

    # results.append(df.Histo1D(("SMWeights", "", *bins_weight), "RecoSMWeights", "nominal_weight"))
    # results.append(df.Histo1D(("BSMWeights", "", *bins_weight), "RecoBSMWeights", "nominal_weight"))
    # results.append(df.Histo1D(("MixtureWeights", "", *bins_weight), "RecoMixtureWeights", "nominal_weight"))
    # results.append(df.Histo1D(("NegMixtureWeights", "", *bins_weight), "RecoNegMixtureWeights", "nominal_weight"))
    # results.append(df.Histo1D(("InterferenceWeights", "", *bins_weight), "RecoInterferenceWeights", "nominal_weight"))
    # results.append(df.Histo1D(("NegInterferenceWeights", "", *bins_weight), "RecoNegInterferenceWeights", "nominal_weight"))

    # results.append(df.Histo1D(("D_0Minus", "", *bins_dis), "D_0Minus", "nominal_weight"))
    # results.append(df.Histo1D(("D_CP", "", *bins_cos), "D_CP", "nominal_weight"))
    # results.append(df.Histo1D(("D_CP_NEG", "", *bins_cos), "D_CP_Neg", "nominal_weight"))
    # results.append(df.Histo1D(("D_CPNORM", "", *bins_cos), "D_CPNORM", "nominal_weight"))
    # results.append(df.Histo2D(("D_0Minus vs D_CP", "", *(bins_cos + bins_dis)), "D_CP", "D_0Minus", "nominal_weight"))


    # results.append(df.Histo1D(("D_0Minus_SM", "", *bins_dis), "D_0Minus", "RecoSMWeights"))
    # results.append(df.Histo1D(("D_0Minus_BSM", "", *bins_dis), "D_0Minus", "RecoBSMWeights"))
    # results.append(df.Histo1D(("D_0Minus_MIX", "", *bins_dis), "D_0Minus", "RecoMixtureWeights"))
    # results.append(df.Histo1D(("D_0Minus_INT", "", *bins_dis), "D_0Minus", "RecoInterferenceWeights"))

    # results.append(df.Histo1D(("D_0MinusNORM_SM", "", *bins_dis), "D_0Minus", "RecoSMWeightsNORM"))
    # results.append(df.Histo1D(("D_0MinusNORM_SM_INV", "", *bins_dis), "D_0Minus", "RecoSMWeightsINV"))
    # results.append(df.Histo1D(("D_0MinusNORM_BSM", "", *bins_dis), "D_0Minus", "RecoBSMWeightsNORM"))
    # results.append(df.Histo1D(("D_0MinusNORM_MIX", "", *bins_dis), "D_0Minus", "RecoMixtureWeightsNORM"))
    # results.append(df.Histo1D(("D_0MinusNORM_NEG_MIX", "", *bins_dis), "D_0Minus", "RecoNegMixtureWeightsNORM"))
    # results.append(df.Histo1D(("D_0MinusNORM_INT", "", *bins_dis), "D_0Minus", "RecoInterferenceWeightsNORM"))

    # results.append(df.Histo1D(("D_CP_SM", "", *bins_cos), "D_CP", "RecoSMWeights"))
    # results.append(df.Histo1D(("D_CP_BSM", "", *bins_cos), "D_CP", "RecoBSMWeights"))
    # results.append(df.Histo1D(("D_CP_MIX", "", *bins_cos), "D_CP", "RecoMixtureWeights"))
    # results.append(df.Histo1D(("D_CP_INT", "", *bins_cos), "D_CP", "RecoInterferenceWeights"))

    # results.append(df.Histo1D(("D_CPNORM_SM", "", *bins_cos), "D_CP", "RecoSMWeightsNORM"))
    # results.append(df.Histo1D(("D_CPNORM_SM_INV", "", *bins_cos), "D_CP", "RecoSMWeightsINV"))
    # results.append(df.Histo1D(("D_CPNORM_BSM", "", *bins_cos), "D_CP", "RecoBSMWeightsNORM"))
    # results.append(df.Histo1D(("D_CPNORM_MIX", "", *bins_cos), "D_CP", "RecoMixtureWeightsNORM"))
    # results.append(df.Histo1D(("D_CPNORM_NEG_MIX", "", *bins_cos), "D_CP", "RecoNegMixtureWeightsNORM"))
    # results.append(df.Histo1D(("D_CPNORM_INT", "", *bins_cos), "D_CP", "RecoInterferenceWeightsNORM"))

    # results.append(df.Histo2D(("D_0MinusNORM vs D_CPNORM (SM)", "", *(bins_cos + bins_dis)), "D_CP", "D_0Minus", "RecoSMWeightsNORM"))
    # results.append(df.Histo2D(("D_0MinusNORM vs D_CPNORM (BSM)", "", *(bins_cos + bins_dis)), "D_CP", "D_0Minus", "RecoBSMWeightsNORM"))
    # results.append(df.Histo2D(("D_0MinusNORM vs D_CPNORM (MIX)", "", *(bins_cos + bins_dis)), "D_CP", "D_0Minus", "RecoMixtureWeightsNORM"))
    # results.append(df.Histo2D(("D_0MinusNORM vs D_CPNORM (INT)", "", *(bins_cos + bins_dis)), "D_CP", "D_0Minus", "RecoInterferenceWeightsNORM"))
    
   


    if do_syst:

        # muon momentum scale
        df = df.Define("leps_scaleup", "FCCAnalyses::ZHfunctions::lepton_momentum_scale(1e-5)(leps)")
        df = df.Define("leps_scaledw", "FCCAnalyses::ZHfunctions::lepton_momentum_scale(-1e-5)(leps)")

        df = df.Define("zbuilder_result_scaleup", f"FCCAnalyses::ZHfunctions::resonanceBuilder_mass_recoil(91.2, 125, 0.4, 240, {'true' if do_gen else 'false'})(leps_scaleup, MCRecoAssociations0, MCRecoAssociations1, ReconstructedParticles, Particle, Particle0, Particle1)")
        df = df.Define("zbuilder_result_scaledw", f"FCCAnalyses::ZHfunctions::resonanceBuilder_mass_recoil(91.2, 125, 0.4, 240, {'true' if do_gen else 'false'})(leps_scaledw, MCRecoAssociations0, MCRecoAssociations1, ReconstructedParticles, Particle, Particle0, Particle1)")
        df = df.Define("zll_scaleup", "ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>{zbuilder_result_scaleup[0]}")
        df = df.Define("zll_scaledw", "ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>{zbuilder_result_scaledw[0]}")
        df = df.Define("zll_recoil_scaleup", "FCCAnalyses::ReconstructedParticle::recoilBuilder(240)(zll_scaleup)")
        df = df.Define("zll_recoil_scaledw", "FCCAnalyses::ReconstructedParticle::recoilBuilder(240)(zll_scaledw)")
        df = df.Define("zll_recoil_m_scaleup", "FCCAnalyses::ReconstructedParticle::get_mass(zll_recoil_scaleup)[0]")
        df = df.Define("zll_recoil_m_scaledw", "FCCAnalyses::ReconstructedParticle::get_mass(zll_recoil_scaledw)[0]")

        results.append(df.Histo2D(("zll_recoil_m_scaleup", "", *(bins_recoil_fine + bins_cat)), "zll_recoil_m_scaleup", "zll_category", "nominal_weight"))
        results.append(df.Histo2D(("zll_recoil_m_scaledw", "", *(bins_recoil_fine + bins_cat)), "zll_recoil_m_scaledw", "zll_category", "nominal_weight"))


        # sqrt uncertainty
        df = df.Define("zll_recoil_sqrtsup", "FCCAnalyses::ReconstructedParticle::recoilBuilder(240.002)(zll)")
        df = df.Define("zll_recoil_sqrtsdw", "FCCAnalyses::ReconstructedParticle::recoilBuilder(239.998)(zll)")
        df = df.Define("zll_recoil_m_sqrtsup", "FCCAnalyses::ReconstructedParticle::get_mass(zll_recoil_sqrtsup)[0]")
        df = df.Define("zll_recoil_m_sqrtsdw", "FCCAnalyses::ReconstructedParticle::get_mass(zll_recoil_sqrtsdw)[0]")

        results.append(df.Histo2D(("zll_recoil_m_sqrtsup", "", *(bins_recoil_fine + bins_cat)), "zll_recoil_m_sqrtsup", "zll_category", "nominal_weight"))
        results.append(df.Histo2D(("zll_recoil_m_sqrtsdw", "", *(bins_recoil_fine + bins_cat)), "zll_recoil_m_sqrtsdw", "zll_category", "nominal_weight"))
    #    df.Snapshot("tree", f"{dataset}.root", {"zll_m", "cos_1", "cos_2", "phi"})
    #for ele in dataset:
       # df.Snapshot("tree", f"FCCAnalysisOut/BkgTemplate/{ele}.root", {"zll_m", "cos_1" "cos_2","phi"})
    # branchlist = ROOT.std.vector('std::string')()
    # branchlist.push_back('zll_recoil_m')
    # branchlist.push_back('D_0Minus')
    # branchlist.push_back('D_CP')
    # branchlist.push_back('cos_1')
    # branchlist.push_back('cos_2')
    # branchlist.push_back('phi')
    # branchlist.push_back('D_0Minus_Equal')
    # branchlist.push_back('D_CP_Equal')

    # sig_branchlist = ROOT.std.vector('std::string')()
    # sig_branchlist.push_back('zll_recoil_m')
    # sig_branchlist.push_back('D_0Minus')
    # sig_branchlist.push_back('D_CP')

    # sig_branchlist.push_back('D_0Minus_Equal')
    # sig_branchlist.push_back('D_CP_Equal')

    # sig_branchlist.push_back('cos_1')
    # sig_branchlist.push_back('cos_2')
    # sig_branchlist.push_back('phi')
    # sig_branchlist.push_back('RecoSMWeightsNORM')
    # sig_branchlist.push_back('RecoBSMWeightsNORM')
    # sig_branchlist.push_back('RecoBSMWeightsEqualNORM')
    # sig_branchlist.push_back('RecoMixtureWeightsNORM')
    # sig_branchlist.push_back('RecoNegMixtureWeightsNORM')
    
    # sig_branchlist.push_back('SMWeights')
    # sig_branchlist.push_back('SMWeightsNORM')

    # sig_branchlist.push_back('BSMWeights')
    # sig_branchlist.push_back('BSMWeightsNORM')
    
    # sig_branchlist.push_back('BSMWeightsEqual')
    # sig_branchlist.push_back('BSMWeightsEqualNORM')

    # sig_branchlist.push_back('InterferenceWeights')
    # sig_branchlist.push_back('InterferenceWeightsNORM')

    # sig_branchlist.push_back('EqualInterferenceWeights')
    # sig_branchlist.push_back('EqualInterferenceWeightsNORM')

    # sig_branchlist.push_back('MixtureWeights')
    # sig_branchlist.push_back('MixtureWeightsNORM')
    
    # sig_branchlist.push_back('NegMixtureWeights')
    # sig_branchlist.push_back('NegMixtureWeightsNORM')

    # sig_branchlist.push_back('EqualMixtureWeights')
    # sig_branchlist.push_back('EqualMixtureWeightsNORM')


    # sig_branchlist.push_back('NegEqualMixtureWeights')
    # sig_branchlist.push_back('NegEqualMixtureWeightsNORM')
    #df.Snapshot("tree", f"FCCAnalysisOut/{flavor}/bkg_{dataset}.root", {"zll_recoil_m", "D_0Minus",  "D_CP", "RecoSMWeightsNORM", "RecoBSMWeightsNORM", "RecoMixtureWeightsNORM", "RecoNegMixtureWeightsNORM", "SMWeightsNORM", "BSMWeightsNORM", "InterferenceWeightsNORM", "MixtureWeightsNORM", "NegMixtureWeightsNORM"})
    #df.Snapshot("tree", f"muonTestingHopefullyFixed/{dataset}.root", branchlist)
    # df.Snapshot("tree", f"FCCAnalysisOut/May21Sig.root", sig_branchlist)
    return results, weightsum
