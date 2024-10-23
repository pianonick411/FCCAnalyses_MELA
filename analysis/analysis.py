
# analysis config
flavor = "mumu" # mumu or ee
do_mass = True # for mass analysis, extra cut on cos(theta_miss)
do_gen = False # replace reco-particles by the corresponding gen particle
do_syst = False

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
    
    # signal
    f'wzp6_ee_{flavor}H_ecm240': {'fraction':1},
}

# if do_mass:
#     processList[f'wzp6_ee_{flavor}H_mH-higher-100MeV_ecm240'] = {'fraction':1}
#     processList[f'wzp6_ee_{flavor}H_mH-higher-50MeV_ecm240'] = {'fraction':1}
#     processList[f'wzp6_ee_{flavor}H_mH-lower-100MeV_ecm240'] = {'fraction':1}
#     processList[f'wzp6_ee_{flavor}H_mH-lower-50MeV_ecm240'] = {'fraction':1}
#     if do_syst:
#         processList[f'wzp6_ee_{flavor}H_BES-higher-1pc_ecm240'] = {'fraction':1}
#         processList[f'wzp6_ee_{flavor}H_BES-lower-1pc_ecm240'] = {'fraction':1}

sigProcs = ["wzp6_ee_mumuH_ecm240", "wzp6_ee_eeH_ecm240"]


# Production tag when running over EDM4Hep centrally produced events, this points to the yaml files for getting sample statistics
prodTag     = "FCCee/winter2023/IDEA/"

# Link to the dictonary that contains all the cross section informations etc...
procDict = "FCCee_procDict_winter2023_IDEA.json"

# additional/custom C++ functions, defined in header files (optional)
includePaths = ["functions.h"]


#Optional: output directory, default is local running directory
outputDir   = "JanAnalysis/"

#f"output_{flavor}/"


# optional: ncpus, default is 4, -1 uses all cores available
nCPUS       = -1

# scale the histograms with the cross-section and integrated luminosity
doScale = True
intLumi = 7200000 # 7.2 /ab


# define some binning for various histograms
bins_p_mu = (2000, 0, 200) # 100 MeV bins
bins_m_ll = (2000, 0, 200) # 100 MeV bins
bins_p_ll = (200, 0, 200) # 1 GeV bins
bins_recoil = (20000, 0, 200) # 10 MeV bins 
bins_recoil_fine = (20000, 120, 140) # 1 MeV bins 
bins_cosThetaMiss = (10000, 0, 1)

bins_theta = (500, -5, 5)
bins_eta = (600, -3, 3)
bins_phi = (500, -5, 5)
bins_aco = (400, -4, 4)

bins_count = (50, 0, 50)
bins_charge = (10, -5, 5)
bins_iso = (500, 0, 5)
bins_cat = (10, 0, 10)
bins_resolution = (10000, 0.95, 1.05)



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
    if flavor == "mumu":
        df = df.Alias("Lepton0", "Muon#0.index")
    else:
        df = df.Alias("Lepton0", "Electron#0.index")

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
    df = df.Define("zll_m", "FCCAnalyses::ReconstructedParticle::get_mass(zll)[0]")
    df = df.Define("zll_p", "FCCAnalyses::ReconstructedParticle::get_p(zll)[0]")
    df = df.Define("zll_recoil", "FCCAnalyses::ReconstructedParticle::recoilBuilder(240)(zll)")
    df = df.Define("zll_recoil_m", "FCCAnalyses::ReconstructedParticle::get_mass(zll_recoil)[0]")
    df = df.Define("zll_category", "FCCAnalyses::ZHfunctions::polarAngleCategorization(0.8, 2.34)(zll_leps)")

    df = df.Define("zll_leps_p", "FCCAnalyses::ReconstructedParticle::get_p(zll_leps)")
    df = df.Define("zll_leps_theta", "FCCAnalyses::ReconstructedParticle::get_theta(zll_leps)")

    df = df.Define("missingEnergy", "FCCAnalyses::ZHfunctions::missingEnergy(240., ReconstructedParticles)")
    df = df.Define("cosTheta_miss", "FCCAnalyses::ZHfunctions::get_cosTheta_miss(missingEnergy)")

    df = df.Define("acoplanarity", "FCCAnalyses::ZHfunctions::acoplanarity(leps)")
    df = df.Define("acolinearity", "FCCAnalyses::ZHfunctions::acolinearity(leps)")

    if dataset in sigProcs:
        results.append(df.Histo1D(("higgs_decay_cut2", "", *bins_count), "daughter_higgs_collapsed", "nominal_weight"))

    #########
    ### CUT 3: Z mass window
    #########
    results.append(df.Histo1D(("zll_m_nmone", "", *bins_m_ll), "zll_m", "nominal_weight"))
    df = df.Filter("zll_m > 86 && zll_m < 96")
    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut3"))
    
    if dataset in sigProcs:
        results.append(df.Histo1D(("higgs_decay_cut3", "", *bins_count), "daughter_higgs_collapsed", "nominal_weight"))

    #########
    ### CUT 4: Z momentum
    #########
    results.append(df.Histo1D(("zll_p_nmone", "", *bins_p_mu), "zll_p"))
    df = df.Filter("zll_p > 20 && zll_p < 70")
    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut4", "nominal_weight"))
    results.append(df.Histo1D(("zll_recoil_cut4", "", *bins_recoil), "zll_recoil_m", "nominal_weight"))
    if dataset in sigProcs:
        results.append(df.Histo1D(("higgs_decay_cut4", "", *bins_count), "daughter_higgs_collapsed", "nominal_weight"))

    #########
    ### CUT 5: recoil cut
    #########
    results.append(df.Histo1D(("zll_recoil_m_nmone", "", *bins_recoil), "zll_recoil_m", "nominal_weight"))
    df = df.Filter("zll_recoil_m < 140 && zll_recoil_m > 120")
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
    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut6", "nominal_weight"))

    # final histograms
    results.append(df.Histo1D(("leps_p", "", *bins_p_mu), "leps_p", "nominal_weight"))
    results.append(df.Histo1D(("zll_p", "", *bins_p_mu), "zll_p", "nominal_weight"))
    results.append(df.Histo1D(("zll_m", "", *bins_m_ll), "zll_m", "nominal_weight"))
    results.append(df.Histo1D(("zll_recoil_m", "", *bins_recoil), "zll_recoil_m", "nominal_weight"))

    results.append(df.Histo1D(("cosThetaMiss", "", *bins_cosThetaMiss), "cosTheta_miss", "nominal_weight"))
    results.append(df.Histo1D(("acoplanarity", "", *bins_aco), "acoplanarity", "nominal_weight"))
    results.append(df.Histo1D(("acolinearity", "", *bins_aco), "acolinearity", "nominal_weight"))

    results.append(df.Histo2D(("zll_recoil_m_cat", "", *(bins_recoil_fine + bins_cat)), "zll_recoil_m", "zll_category", "nominal_weight"))


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

    weightsum = df.Sum("nominal_weight")
    threading.Thread(target=print_process_id).start()
    return results, weightsum
threading.Thread(target=print_process_id).start()
    
