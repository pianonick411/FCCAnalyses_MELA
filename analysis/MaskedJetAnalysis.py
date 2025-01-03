
# analysis config
do_gen = False # replace reco-particles by the corresponding gen particle
do_weights = False
runBatch = True
jet_flavor = ""


import os, copy 
import threading 

import psutil

def print_process_id(): 
    print(threading.current_thread, os.getpid())





# list of processes
processList = {
    # main backgrounds
'p8_ee_WW_ecm240': {'fraction':1, 'chunks':1500},
# 'p8_ee_ZZ_ecm240': {'fraction':1, 'chunks':2},
    #'wzp6_ee_tautau_ecm240': {'fraction':1},
    #'wzp6_ee_mumu_ecm240' if flavor=="mumu" else 'wzp6_ee_ee_Mee_30_150_ecm240': {'fraction':1},
# 'wzp6_ee_nunuH_ecm240': {'fraction':1, 'chunks':5},
 "p8_ee_Zqq_ecm240": {'fraction':1, 'chunks':1500},

    # rare backgrounds
    #f'wzp6_egamma_eZ_Z{flavor}_ecm240': {'fraction':1},
    #f'wzp6_gammae_eZ_Z{flavor}_ecm240': {'fraction':1},
    #f'wzp6_gaga_{flavor}_60_ecm240': {'fraction':1},
    #'wzp6_gaga_tautau_60_ecm240': {'fraction':1},
    #'wzp6_ee_nuenueZ_ecm240': {'fraction':.01},

    #Backgrounds for Z --> bb\

    
    # signals
    #'wzp6_ee_nunuH_Hbb_ecm240': {'fraction':0.01},
    
# f'wzp6_ee_qqH_ecm240': {'fraction':1},



#f'wzp6_ee_bbH_Hbb_ecm240': {'fraction':1},
# f'wzp6_ee_bbH_Hcc_ecm240': {'fraction':1},
#  f'wzp6_ee_bbH_Hss_ecm240': {'fraction':1},
#     f'wzp6_ee_bbH_Hgg_ecm240': {'fraction':1},
#      'wzp6_ee_bbH_Htautau_ecm240':{'fraction':1},
#  'wzp6_ee_bbH_HZZ_ecm240':{'fraction':1},
#  'wzp6_ee_bbH_HWW_ecm240':{'fraction':1},



#    f'wzp6_ee_ccH_Hbb_ecm240': {'fraction':1},
#     f'wzp6_ee_ccH_Hcc_ecm240': {'fraction':1},
#     f'wzp6_ee_ccH_Hss_ecm240': {'fraction':1},
#     f'wzp6_ee_ccH_Hgg_ecm240': {'fraction':1},
#    'wzp6_ee_ccH_Htautau_ecm240':{'fraction':1},
#    'wzp6_ee_ccH_HZZ_ecm240':{'fraction':1},
#    'wzp6_ee_ccH_HWW_ecm240':{'fraction':1},

    # f'wzp6_ee_ssH_Hbb_ecm240': {'fraction':1},
    # f'wzp6_ee_ssH_Hcc_ecm240': {'fraction':1},
    # f'wzp6_ee_ssH_Hss_ecm240': {'fraction':1},
    # f'wzp6_ee_ssH_Hgg_ecm240': {'fraction':1},
#     'wzp6_ee_ssH_Htautau_ecm240':{'fraction':1},
#    'wzp6_ee_ssH_HZZ_ecm240':{'fraction':1},
#    'wzp6_ee_ssH_HWW_ecm240':{'fraction':1},

}


sigProcs = ["wzp6_ee_qqH_ecm240", "wzp6_ee_bbH_Hbb_ecm240", "wzp6_ee_bbH_Hcc_ecm240", "wzp6_ee_bbH_Hss_ecm240", "wzp6_ee_bbH_Hgg_ecm240", "wzp6_ee_bbH_Htautau_ecm240", "wzp6_ee_bbH_HZZ_ecm240", "wzp6_ee_bbH_HWW_ecm240", "wzp6_ee_ccH_Hbb_ecm240", "wzp6_ee_ccH_Hcc_ecm240", "wzp6_ee_ccH_Hss_ecm240", "wzp6_ee_ccH_Hgg_ecm240", "wzp6_ee_ccH_Htautau_ecm240", "wzp6_ee_ccH_HZZ_ecm240", "wzp6_ee_ccH_HWW_ecm240", "wzp6_ee_ssH_Hbb_ecm240", "wzp6_ee_ssH_Hcc_ecm240", "wzp6_ee_ssH_Hss_ecm240", "wzp6_ee_ssH_Hgg_ecm240", "wzp6_ee_ssH_Htautau_ecm240", "wzp6_ee_ssH_HZZ_ecm240", "wzp6_ee_ssH_HWW_ecm240"]


# Production tag when running over EDM4Hep centrally produced events, this points to the yaml files for getting sample statistics
prodTag     = "FCCee/winter2023/IDEA/"

# Link to the dictonary that contains all the cross section informations etc...
procDict = "FCCee_procDict_winter2023_IDEA.json"

# additional/custom C++ functions, defined in header files (optional)
includePaths = ["functions.h", "JHUfunctions.h"]


#Optional: output directory, default is local running directory
outputDir   = "FCCAnalysisOut/Oct27/"

#f"output_{flavor}/"

# NICK FROM HERE TO LINE 92 is NEEDED
## latest particle transformer model, trained on 9M jets in winter2023 samples
model_name = "fccee_flavtagging_edm4hep_wc_v1"

## model files needed for unit testing in CI
url_model_dir = "https://fccsw.web.cern.ch/fccsw/testsamples/jet_flavour_tagging/winter2023/wc_pt_13_01_2022/"
url_preproc = "{}/{}.json".format(url_model_dir, model_name)
url_model = "{}/{}.onnx".format(url_model_dir, model_name)

## model files locally stored on /eos
model_dir = (
    "/eos/experiment/fcc/ee/jet_flavour_tagging/winter2023/wc_pt_13_01_2022/"
)
local_preproc = "{}/{}.json".format(model_dir, model_name)
local_model = "{}/{}.onnx".format(model_dir, model_name)

## get local file, else download from url
def get_file_path(url, filename):
    if os.path.exists(filename):
        return os.path.abspath(filename)
    else:
        urllib.request.urlretrieve(url, os.path.basename(url))
        return os.path.basename(url)


weaver_preproc = get_file_path(url_preproc, local_preproc)
weaver_model = get_file_path(url_model, local_model)

from addons.ONNXRuntime.jetFlavourHelper import JetFlavourHelper
from addons.FastJet.jetClusteringHelper import (
    ExclusiveJetClusteringHelper,
)

jetFlavourHelper = None
jetClusteringHelper = None

#END SECTION FOR NICK
#WHOLE JET SEQUENCE IS NEW START HERE
def jet_sequence(df, collections, output_branches, tag=""):

    ## define jet clustering parameters
    df = df.Define("missingEnergy", "FCCAnalyses::ZHfunctions::missingEnergy(240., ReconstructedParticles)")
    df = df.Define("cosTheta_miss", "FCCAnalyses::ZHfunctions::get_cosTheta_miss(missingEnergy)")

    njets = 4

    jetClusteringHelper = ExclusiveJetClusteringHelper(collections["PFParticles"], njets, tag)
    ## run jet clustering

    df = jetClusteringHelper.define(df)

    output_branches += jetClusteringHelper.outputBranches()
   

    jets_p4 = "tlv_jets"
    mjj = "mjj"

    if tag != "":
        jets_p4 = "tlv_jets_{}".format(tag)
        mjj = "mjj_{}".format(tag)
        # COULD PROBABLY JUST ADD YOUR TLV FUNCTION SOMEWHERE HERE, I THINK jets_p4 IS JUST THAT
    df = df.Filter("{}.size() > 1".format(jetClusteringHelper.jets))
    df = df.Define(jets_p4, "JetConstituentsUtils::compute_tlv_jets({})".format(jetClusteringHelper.jets))
    df = df.Define(mjj, "JetConstituentsUtils::InvariantMass({}[0], {}[1])".format(jets_p4, jets_p4))
    output_branches.append(mjj)

    ## define jet flavour tagging parameters

    jetFlavourHelper = JetFlavourHelper(
        collections,
        jetClusteringHelper.jets,
        jetClusteringHelper.constituents,
        tag,
    )

    ## define observables for tagger
    df = jetFlavourHelper.define(df)

    ## tagger inference
    df = jetFlavourHelper.inference(weaver_preproc, weaver_model, df)

    output_branches += jetFlavourHelper.outputBranches()

    return df
#END NEXT SECTION FOR NICK

# extracting jet variables - grafted from loukas' scripts - THIS WHOLE FUNCTION IS NEW/NEEDED! CAN PICK AND CHOOSE VARIABLES. I PERFORM ALL JET MATH AND SUCH HERE  
def analysis_sequence(df, collections, analysis_branches, tag=""):
    anatag = tag
    if tag != "":
        anatag = "_{}".format(tag)
# ____________________________________________________________
# ____________________________________________________________
 # Variables
    for x in range(0, 4):
        df = (df.Define("jet{}_scoreQ{}".format(x,anatag), "recojet_isQ{}[{}]".format(anatag, x)))
#        df = (df.Define("jet{}_scoreU{}".format(x,anatag), "recojet_isU{}[{}]".format(anatag, x)))
 #       df = (df.Define("jet{}_scoreTAU{}".format(x,anatag), "recojet_isTAU{}[{}]".format(anatag, x)))
        df = (df.Define("jet{}_scoreB{}".format(x,anatag), "recojet_isB{}[{}]".format(anatag, x)))
        df = (df.Define("jet{}_scoreC{}".format(x,anatag), "recojet_isC{}[{}]".format(anatag, x)))
        df = (df.Define("jet{}_scoreS{}".format(x,anatag), "recojet_isS{}[{}]".format(anatag, x)))
        df = (df.Define("jet{}_scoreG{}".format(x,anatag), "recojet_isG{}[{}]".format(anatag, x)))
        df = df.Define("jet{}_ScoreVec".format(x), "FCCAnalyses::JHUfunctions::MakeScoreVector(jet{}_scoreQ, jet{}_scoreB, jet{}_scoreC, jet{}_scoreS, jet{}_scoreG)".format(x,x,x,x,x))
    df = df.Define("VectorOfScoreVectors", "std::vector<Vec_f>{jet0_ScoreVec, jet1_ScoreVec, jet2_ScoreVec, jet3_ScoreVec}")
    for x in range(1, 9):
        df = (df.Define("d_{}{}{}".format(x,x+1,anatag), "JetClusteringUtils::get_exclusive_dmerge(_jet{}, {})".format(anatag, x))) #dmerge from x+1 to x


    df=(df.Define("recojet_e{}".format(anatag), "JetClusteringUtils::get_e(jet{})".format(anatag)))
    df=(df.Define("recojet_p{}".format(anatag), "JetClusteringUtils::get_p(jet{})".format(anatag)))
    df=(df.Define("recojet_px{}".format(anatag), "JetClusteringUtils::get_px(jet{})".format(anatag)))
    df=(df.Define("recojet_py{}".format(anatag), "JetClusteringUtils::get_py(jet{})".format(anatag)))
    df=(df.Define("recojet_pz{}".format(anatag), "JetClusteringUtils::get_pz(jet{})".format(anatag)))
    df=(df.Define("recojet_m{}".format(anatag), "JetClusteringUtils::get_m(jet{})".format(anatag)))
    df=(df.Define("recojet_theta{}".format(anatag), "JetClusteringUtils::get_theta(jet{})".format(anatag)))
    df=(df.Define("recojet_phi{}".format(anatag), "JetClusteringUtils::get_phi_std(jet{})".format(anatag)))
    # jets properties still reco
# THIS ORGANIZES PRIOR SECTION INTO 4 JETS I BELIEVE 
    for x in range(0, 4):
        df=(df.Define("jet{}_e{}".format(x,anatag), "recojet_e{}[{}]".format(anatag,x)))
        df=(df.Define("jet{}_m{}".format(x,anatag), "recojet_m{}[{}]".format(anatag,x)))
        df=(df.Define("jet{}_p{}".format(x,anatag), "recojet_p{}[{}]".format(anatag,x)))
        df=(df.Define("jet{}_px{}".format(x,anatag), "recojet_px{}[{}]".format(anatag,x)))
        df=(df.Define("jet{}_py{}".format(x,anatag), "recojet_py{}[{}]".format(anatag,x)))
        df=(df.Define("jet{}_pz{}".format(x,anatag), "recojet_pz{}[{}]".format(anatag,x)))
        df=(df.Define("jet{}_theta{}".format(x,anatag), "recojet_theta{}[{}]".format(anatag,x)))
        df=(df.Define("jet{}_PVector{}".format(x, anatag),"TVector3(jet{}_px{}, jet{}_py{}, jet{}_pz{})".format(x, anatag, x, anatag, x, anatag)))
        df=(df.Define("jet{}_phi{}".format(x,anatag), "recojet_phi{}[{}]".format(anatag,x)))

    # apply correction
#    df = df.Define("jets_tlv_corr{}".format(anatag), "FCCAnalyses::energyReconstructFourJet(recojet_px{}, recojet_py{}, recojet_pz{}, recojet_e{})".format(anatag, anatag, anatag, anatag))

 #   for x in range(0, 4):
  #      df = df.Define("jet{}_e_corr{}".format(x,anatag), "jets_tlv_corr[{}]{}.E()".format(x, anatag))
   #     df = df.Define("jet{}_px_corr{}".format(x,anatag), "jets_tlv_corr[{}]{}.Px()".format(x, anatag))
    #    df = df.Define("jet{}_py_corr{}".format(x,anatag), "jets_tlv_corr[{}]{}.Py()".format(x, anatag))
     #   df = df.Define("jet{}_pz_corr{}".format(x,anatag), "jets_tlv_corr[{}]{}.Pz()".format(x, anatag))
     #   df=  df.Define("jet{}_PVector_corr{}".format(x, anatag),"TVector3(jets_tlv_corr[{}]{}.Px(), jets_tlv_corr[{}]{}.Py(), jets_tlv_corr[{}]{}.Pz())".format(x, anatag, x, anatag, x, anatag))
      #  df = df.Define("jet{}_p_corr{}".format(x,anatag), "jet{}_PVector_corr{}.Mag()".format(x, anatag))
      #  df = df.Define("jet{}_theta_corr{}".format(x,anatag), "jet{}_PVector_corr{}.Theta()".format(x, anatag))
      #  df = df.Define("jet{}_phi_corr{}".format(x,anatag), "jets_tlv_corr[{}]{}.Phi()".format(x, anatag))


    #df = df.Define("chi2_corr{}".format(anatag), "jets_tlv_corr[4]{}.E()".format(anatag))
    #df = df.Define("flag_corr{}".format(anatag), "jets_tlv_corr[5]{}.E()".format(anatag))

#    df = df.Define("jet_sum_e_corr{}".format(anatag), "jet0_e_corr{}+jet1_e_corr{}+jet2_e_corr{}+jet3_e_corr{}".format(anatag,anatag,anatag,anatag))

    df = (df.Define("P4_vis{}".format(anatag), "ReconstructedParticle::get_P4vis({})".format(collections["PFParticles"])))
    df = (df.Define("vis_E{}".format(anatag), "P4_vis{}.E()".format(anatag)))
    df = (df.Define("vis_M{}".format(anatag), "P4_vis{}.M()".format(anatag)))
    df = (df.Define("P3_vis{}".format(anatag),"TVector3(P4_vis{}.Px(), P4_vis{}.Py(), P4_vis{}.Pz())".format(anatag, anatag, anatag)))
    df = (df.Define("vis_P{}".format(anatag), "P3_vis{}.Mag()".format(anatag)))
    df = (df.Define("vis_theta{}".format(anatag), "P3_vis{}.Theta()".format(anatag)))
    df = (df.Define("vis_phi{}".format(anatag), "P3_vis{}.Phi()".format(anatag)))
    for x in range(0, 4):
        df = (df.Define("jet{}_nconst{}".format(x, anatag), "jet_nconst{}[{}]".format(anatag,x)))
        df = (df.Define("jet{}_nmu{}".format(x, anatag), "jet_nmu{}[{}]".format(anatag, x)))
        df = (df.Define("jet{}_nel{}".format(x, anatag), "jet_nel{}[{}]".format(anatag, x)))
        df = (df.Define("jet{}_nchad{}".format(x, anatag), "jet_nchad{}[{}]".format(anatag, x)))
        #electrons
    df = (df.Alias("Electron0{}".format(anatag), "{}#0.index".format(collections["Electrons"])))
    df= df.Define("electrons{}".format(anatag),"ReconstructedParticle::get(Electron0{}, {})".format(anatag, collections["PFParticles"]), )
    df = df.Define("event_nel{}".format(anatag), "electrons{}.size()".format(anatag))  # are these isolated?
    df = df.Define("electrons_p{}".format(anatag), "ReconstructedParticle::get_p(electrons{})[0]".format(anatag))
        # muons
    df = df.Alias("Muon0{}".format(anatag), "{}#0.index".format(collections["Muons"]))
    df =   df.Define("muons{}".format(anatag),"ReconstructedParticle::get(Muon0{}, {})".format(anatag, collections["PFParticles"]),)
    df =  df.Define("event_nmu{}".format(anatag), "muons{}.size()".format(anatag))
    df = df.Define("muons_p{}".format(anatag), "ReconstructedParticle::get_p(muons{})[0]".format(anatag))

    #Missing Energy: 
    
    
    for x in range(0, 3):
        for y in range(1, 4):
            if y > x:
                df = (df.Define("M_j{}_j{}{}".format(x, y, anatag), "(tlv_jets{}[{}] + tlv_jets{}[{}]).M()".format(anatag, x, anatag, y)))
#                df = (df.Define("M_j{}_j{}{}_recoil".format(x, y, anatag), "JetClusteringUtils::recoilBuilder(240)(Take(tlv_jets{}, 2, [{},{}]))".format(anatag, x, y)))
                df = (df.Define("deltaTheta_j{}_j{}{}".format(x, y, anatag), "jet{}_PVector{}.Angle(jet{}_PVector{})".format(x, anatag, y, anatag)))
                df = (df.Define("dE_over_avgE_j{}_j{}{}".format(x, y, anatag), "(jet{}_e{}-jet{}_e{})/(jet{}_e{}+jet{}_e{})".format(x, anatag, y, anatag, x, anatag, y, anatag)))
                df = (df.Define("eS_over_eL_j{}_j{}{}".format(x, y, anatag), "jet{}_e{}/jet{}_e{}".format(y, anatag, x, anatag)))
                # Corrected values
    #            df = (df.Define("M_j{}_j{}_corr{}".format(x, y, anatag), "(jets_tlv_corr[{}]{} + jets_tlv_corr[{}]{}).M()".format(x, anatag, y, anatag)))
#                df = (df.Define("M_j{}_j{}_corr{}_recoil".format(x, y, anatag), "JetClusteringUtils::recoilBuilder(240)(jets_tlv_corr{}[{}],jets_tlv_corr{}[{}])".format(anatag, x, anatag, y)))
   #             df = (df.Define("deltaTheta_j{}_j{}_corr{}".format(x, y, anatag), "jet{}_PVector_corr{}.Angle(jet{}_PVector_corr{})".format(x, anatag, y, anatag)))
  #              df = (df.Define("dE_over_avgE_j{}_j{}_corr{}".format(x, y, anatag), "(jet{}_e_corr{}-jet{}_e_corr{})/(jet{}_e_corr{}+jet{}_e_corr{})".format(x, anatag, y, anatag, x, anatag, y, anatag)))
 #               df = (df.Define("eS_over_eL_j{}_j{}_corr{}".format(x, y, anatag), "jet{}_e_corr{}/jet{}_e_corr{}".format(y, anatag, x, anatag)))
# ____________________________________________________________
# ____________________________________________________________

#THIS SECTION IS WHERE WE ADD VARIABLES FOR LATER PLOTTING AND SUCH
# Branches
    for x in range(0, 4):
        analysis_branches.append("jet{}_scoreQ{}".format(x, anatag))
 #       analysis_branches.append("jet{}_scoreU{}".format(x, anatag))
    #    analysis_branches.append("jet{}_scoreTAU{}".format(x, anatag))
        analysis_branches.append("jet{}_scoreB{}".format(x, anatag))
        analysis_branches.append("jet{}_scoreC{}".format(x, anatag))
        analysis_branches.append("jet{}_scoreS{}".format(x, anatag))
        analysis_branches.append("jet{}_scoreG{}".format(x, anatag))
    for x in range(1, 9):
        analysis_branches.append("d_{}{}{}".format(x,x+1,anatag))

    analysis_branches += [
        # predictions
        "event_njet{}".format(anatag),
        "vis_M{}".format(anatag),
        "vis_P{}".format(anatag),
        "vis_E{}".format(anatag),
        "vis_theta{}".format(anatag),
        "vis_phi{}".format(anatag),
    ]
    for x in range(0, 4):
        # observables
        analysis_branches.append("jet{}_e{}".format(x, anatag))
        analysis_branches.append("jet{}_m{}".format(x, anatag))
        analysis_branches.append("jet{}_p{}".format(x, anatag))
        analysis_branches.append("jet{}_px{}".format(x, anatag))
        analysis_branches.append("jet{}_py{}".format(x, anatag))
        analysis_branches.append("jet{}_pz{}".format(x, anatag))
        analysis_branches.append("jet{}_theta{}".format(x, anatag))
        analysis_branches.append("jet{}_phi{}".format(x, anatag))
        analysis_branches.append("jet{}_nconst{}".format(x, anatag))
        analysis_branches.append("jet{}_nel{}".format(x, anatag))
        analysis_branches.append("jet{}_nmu{}".format(x, anatag))
     #   analysis_branches.append("jet{}_e_corr{}".format(x,anatag))
     #   analysis_branches.append("jet{}_p_corr{}".format(x,anatag))
     #   analysis_branches.append("jet{}_px_corr{}".format(x,anatag))
     #   analysis_branches.append("jet{}_py_corr{}".format(x,anatag))
     #   analysis_branches.append("jet{}_pz_corr{}".format(x,anatag))
     #   analysis_branches.append("jet{}_theta_corr{}".format(x,anatag))
     #   analysis_branches.append("jet{}_phi_corr{}".format(x,anatag))
        
    analysis_branches += [
     #   "chi2_corr".format(anatag),
     #   "flag_corr".format(anatag),
        "event_nmu{}".format(anatag),
        "muons_p{}".format(anatag),
        "event_nel{}".format(anatag),
        "electrons_p{}".format(anatag),
    ]
    for x in range(0, 3):
        for y in range(1, 4):
            if y > x:
                analysis_branches.append("M_j{}_j{}{}".format(x, y, anatag))
                analysis_branches.append("deltaTheta_j{}_j{}{}".format(x, y, anatag))
                analysis_branches.append("dE_over_avgE_j{}_j{}{}".format(x, y, anatag))
                analysis_branches.append("eS_over_eL_j{}_j{}{}".format(x, y, anatag))
    #            analysis_branches.append("M_j{}_j{}_corr{}".format(x, y, anatag))
#                analysis_branches.append("deltaTheta_j{}_j{}_corr{}".format(x, y, anatag))
     #           analysis_branches.append("dE_over_avgE_j{}_j{}_corr{}".format(x, y, anatag))
      #          analysis_branches.append("eS_over_eL_j{}_j{}_corr{}".format(x, y, anatag))
# ____________________________________________________________

    return df
#END NEXT SECTION FOR NICK



# optional: ncpus, default is 4, -1 uses all cores available
if do_weights:
    nCPUS       = 1
else: 
    nCPUS = -1

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
bins_binary = (2, 0, 2)

bins_theta = (500, -5, 5)
bins_eta = (600, -3, 3)
bins_phi = (500, -5, 5)
bins_aco = (400, -4, 4)

bins_count = (50, 0, 50)
bins_charge = (10, -5, 5)
bins_iso = (500, 0, 5)
bins_cat = (10, 0, 10)
bins_resolution = (10000, 0.95, 1.05)

bins_jet_score = (100, 0, 1)
bins_jet_scoreSum = (100, 0, 2)

bins_cos = (100, -1.0, 1.0)
bins_phiMELA = (100, -3.15, 3.15)
bins_dis = (100, 0, 1.0)

bins_D0Minus = (4, 0, 1.0)
bins_DCP = (4, -1.0, 1.0)
bins_TemplateMRec = (4, 120, 140)

bins_cos_Template = (10, -1.0, 1.0)
bins_phi_Template = (10, -3.15, 3.15)

bins_E = (240, 0, 240)

bins_dij = (100000, 0, 100000)


# build_graph function that contains the analysis logic, cuts and histograms (mandatory)
def build_graph(df, dataset):

    print("build graph", dataset)
    threading.Thread(target=print_process_id).start()
    p = psutil.Process().cpu_num()
    print("THIS IS P", p)
    results = []
    analysis_branches=[]
    output_branches=[]

    #THE NEXT 20 LINES OR SO ARE SUPER IMPORTANT
    collections1 = {
            "GenParticles": "Particle",
            "PFParticles": "ReconstructedParticles",
            "PFTracks": "EFlowTrack",
            "PFPhotons": "EFlowPhoton",
            "PFNeutralHadrons": "EFlowNeutralHadron",
            "Electrons": "Electron",
            "Muons": "Muon",
            "Photons": "Photons",
            "TrackState": "EFlowTrack_1",
            "TrackerHits": "TrackerHits",
            "CalorimeterHits": "CalorimeterHits",
            "dNdx": "EFlowTrack_2",
            "PathLength": "EFlowTrack_L",
            "Bz": "magFieldBz",
    }

    collections = copy.deepcopy(collections1)
    collections["PFParticles"] = "ReconstructedParticles"
    df = jet_sequence(df, collections,output_branches)
    print(output_branches)
    res_tag=""
    df = analysis_sequence(df, collections, analysis_branches, res_tag)
    #END SECTION


    df = df.Alias("Particle0", "Particle#0.index")
    df = df.Alias("Particle1", "Particle#1.index")
    df = df.Alias("MCRecoAssociations0", "MCRecoAssociations#0.index")
    df = df.Alias("MCRecoAssociations1", "MCRecoAssociations#1.index")
    df = df.Alias("Photon0", "Photon#0.index")
    

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
    df = df.Define("positronDausIdx", "FCCAnalyses::JHUfunctions::get_gen_daus(5, Particle, Particle1)")



    #Investingating these particles that the Best Jets are paired to at truth: 

    # df = df.Define("ParticleZeroMC", "FCCAnalyses::MCParticle::sel_byIndex(0, Particle)")
    # df = df.Define("ParticleZeroVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{ParticleZeroMC}")
    # df = df.Define("ParticleZeroGenStatus", "FCCAnalyses::MCParticle::get_genStatus(ParticleZeroVec_MC)")
    # df = df.Define("ParticleZeroSimStatus", "FCCAnalyses::MCParticle::get_simStatus(ParticleZeroVec_MC)")
    # df = df.Define("ParticleZeroPDG", "FCCAnalyses::MCParticle::get_pdg(ParticleZeroVec_MC)")
    # df = df.Define("ParticleZeroTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(ParticleZeroVec_MC)")
    # df = df.Define("ParticleZeroE","FCCAnalyses::MCParticle::get_e(ParticleZeroVec_MC)" )
    # df = df.Define("ParticleZeroPz", "ParticleZeroTLV[0].Pz()")
    # df = df.Define("ParticleZeroDaus", "FCCAnalyses::ZHfunctions::gen_decay_list_inc_higgs({0}, Particle, Particle1)")
    # df = df.Define("ParticleZeroDausIdx", "FCCAnalyses::JHUfunctions::get_gen_daus(0, Particle, Particle1)")


    # df = df.Define("ParticleOneMC", "FCCAnalyses::MCParticle::sel_byIndex(1, Particle)")
    # df = df.Define("ParticleOneVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{ParticleOneMC}")
    # df = df.Define("ParticleOneGenStatus", "FCCAnalyses::MCParticle::get_genStatus(ParticleOneVec_MC)")
    # df = df.Define("ParticleOneSimStatus", "FCCAnalyses::MCParticle::get_simStatus(ParticleOneVec_MC)")
    # df = df.Define("ParticleOnePDG", "FCCAnalyses::MCParticle::get_pdg(ParticleOneVec_MC)")
    # df = df.Define("ParticleOneTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(ParticleOneVec_MC)")
    # df = df.Define("ParticleOneE","FCCAnalyses::MCParticle::get_e(ParticleOneVec_MC)" )
    # df = df.Define("ParticleOnePz", "ParticleOneTLV[0].Pz()")
    # df = df.Define("ParticleOneDaus", "FCCAnalyses::ZHfunctions::gen_decay_list_inc_higgs({1}, Particle, Particle1)")
    # df = df.Define("ParticleOneDausIdx", "FCCAnalyses::JHUfunctions::get_gen_daus(1, Particle, Particle1)")

    # df = df.Define("ParticleTwoMC", "FCCAnalyses::MCParticle::sel_byIndex(2, Particle)")
    # df = df.Define("ParticleTwoVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{ParticleTwoMC}")
    # df = df.Define("ParticleTwoGenStatus", "FCCAnalyses::MCParticle::get_genStatus(ParticleTwoVec_MC)")
    # df = df.Define("ParticleTwoSimStatus", "FCCAnalyses::MCParticle::get_simStatus(ParticleTwoVec_MC)")
    # df = df.Define("ParticleTwoPDG", "FCCAnalyses::MCParticle::get_pdg(ParticleTwoVec_MC)")
    # df = df.Define("ParticleTwoTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(ParticleTwoVec_MC)")
    # df = df.Define("ParticleTwoE","FCCAnalyses::MCParticle::get_e(ParticleTwoVec_MC)" )
    # df = df.Define("ParticleTwoPz", "ParticleTwoTLV[0].Pz()")
    # df = df.Define("ParticleTwoDaus", "FCCAnalyses::ZHfunctions::gen_decay_list_inc_higgs({2}, Particle, Particle1)")
    # df = df.Define("ParticleTwoDausIdx", "FCCAnalyses::JHUfunctions::get_gen_daus(6, Particle, Particle1)")

    # df = df.Define("ParticleThreeMC", "FCCAnalyses::MCParticle::sel_byIndex(3, Particle)")
    # df = df.Define("ParticleThreeVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{ParticleThreeMC}")
    # df = df.Define("ParticleThreeGenStatus", "FCCAnalyses::MCParticle::get_genStatus(ParticleThreeVec_MC)")
    # df = df.Define("ParticleThreeSimStatus", "FCCAnalyses::MCParticle::get_simStatus(ParticleThreeVec_MC)")
    # df = df.Define("ParticleThreePDG", "FCCAnalyses::MCParticle::get_pdg(ParticleThreeVec_MC)")
    # df = df.Define("ParticleThreeTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(ParticleThreeVec_MC)")
    # df = df.Define("ParticleThreeE","FCCAnalyses::MCParticle::get_e(ParticleThreeVec_MC)" )
    # df = df.Define("ParticleThreePz", "ParticleThreeTLV[0].Pz()")
    # df = df.Define("ParticleThreeDaus", "FCCAnalyses::ZHfunctions::gen_decay_list_inc_higgs({3}, Particle, Particle1)")
    # df = df.Define("ParticleThreeDausIdx", "FCCAnalyses::JHUfunctions::get_gen_daus(3, Particle, Particle1)")


    # df = df.Define("ParticleSixMC", "FCCAnalyses::MCParticle::sel_byIndex(6, Particle)")
    # df = df.Define("ParticleSixVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{ParticleSixMC}")
    # df = df.Define("ParticleSixGenStatus", "FCCAnalyses::MCParticle::get_genStatus(ParticleSixVec_MC)")
    # df = df.Define("ParticleSixSimStatus", "FCCAnalyses::MCParticle::get_simStatus(ParticleSixVec_MC)")
    # df = df.Define("ParticleSixPDG", "FCCAnalyses::MCParticle::get_pdg(ParticleSixVec_MC)")
    # df = df.Define("ParticleSixTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(ParticleSixVec_MC)")
    # df = df.Define("ParticleSixE","FCCAnalyses::MCParticle::get_e(ParticleSixVec_MC)" )
    # df = df.Define("ParticleSixPz", "ParticleSixTLV[0].Pz()")
    # df = df.Define("ParticleSixDaus", "FCCAnalyses::ZHfunctions::gen_decay_list_inc_higgs({6}, Particle, Particle1)")
    # df = df.Define("ParticleSixDausIdx", "FCCAnalyses::JHUfunctions::get_gen_daus(6, Particle, Particle1)")


    # df = df.Define("ParticleSevenMC", "FCCAnalyses::MCParticle::sel_byIndex(7, Particle)")
    # df = df.Define("ParticleSevenVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{ParticleSevenMC}")
    # df = df.Define("ParticleSevenGenStatus", "FCCAnalyses::MCParticle::get_genStatus(ParticleSevenVec_MC)")
    # df = df.Define("ParticleSevenSimStatus", "FCCAnalyses::MCParticle::get_simStatus(ParticleSevenVec_MC)")
    # df = df.Define("ParticleSevenPDG", "FCCAnalyses::MCParticle::get_pdg(ParticleSevenVec_MC)")
    # df = df.Define("ParticleSevenTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(ParticleSevenVec_MC)")
    # df = df.Define("ParticleSevenE","FCCAnalyses::MCParticle::get_e(ParticleSevenVec_MC)" )
    # df = df.Define("ParticleSevenPz", "ParticleSevenTLV[0].Pz()")
    # df = df.Define("ParticleSevenDaus", "FCCAnalyses::ZHfunctions::gen_decay_list_inc_higgs({7}, Particle, Particle1)")
    # df = df.Define("ParticleSevenDausIdx", "FCCAnalyses::JHUfunctions::get_gen_daus(7, Particle, Particle1)")


    
   





    

    # df = df.Define("electronDaus0", "electronDaus[0]")
    
    

    # df = df.Define("higgsE", "FCCAnalyses::MCParticle::get_pdg(higgs_MC)")


    df = df.Define("q", "FCCAnalyses::MCParticle::sel_byIndex(electronDausIdx[1], Particle)")
    df = df.Define("qVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{q}")
    df = df.Define("qPDG", "FCCAnalyses::MCParticle::get_pdg(qVec_MC)")
    df = df.Define("qE","FCCAnalyses::MCParticle::get_e(qVec_MC)" )
    df = df.Define("qTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(qVec_MC)")
    df = df.Define("qPhi", "qTLV[0].Phi()")


    

    df = df.Define("qBar", "FCCAnalyses::MCParticle::sel_byIndex(electronDausIdx[0], Particle)")
    df = df.Define("qBarVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{qBar}")
    df = df.Define("qBarPDG", "FCCAnalyses::MCParticle::get_pdg(qBarVec_MC)")
    df = df.Define("qBarE","FCCAnalyses::MCParticle::get_e(qBarVec_MC)" )
    df = df.Define("qBarTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(qBarVec_MC)")
    df = df.Define("qBarPhi", "qBarTLV[0].Phi()")

    df = df.Define("higgs_MC", "FCCAnalyses::ZHfunctions::sel_pdgID_idx(25,false)(Particle)")
    
    df = df.Define("higgsMC", "FCCAnalyses::MCParticle::sel_byIndex(electronDausIdx[2], Particle)")
    df = df.Define("higgsVec_MC", "ROOT::VecOps::RVec<edm4hep::MCParticleData>{higgsMC}")
    df = df.Define("higgsPDG", "FCCAnalyses::MCParticle::get_pdg(higgsVec_MC)")
    df = df.Define("higgsMCTLV", "FCCAnalyses::JHUfunctions::makeLorentzVectors(higgsVec_MC)")
    df = df.Define("higgs_mass_MC", "higgsMCTLV[0].M()")
    
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



    # df = df.Define("Gen_cos_1_U", "PDGTest == 2 ? Gen_MELA_Angles[1] : 999")
    # df = df.Define("Gen_cos_2_U", "PDGTest == 2 ? Gen_MELA_Angles[2] : 999")
    # df = df.Define("Gen_phi_U", "PDGTest == 2 ? Gen_MELA_Angles[3] : 999")

    # df = df.Define("Gen_cos_1_D", "PDGTest == 1 ? Gen_MELA_Angles[1] : 999")
    # df = df.Define("Gen_cos_2_D", "PDGTest == 1 ? Gen_MELA_Angles[2] : 999")
    # df = df.Define("Gen_phi_D", "PDGTest == 1 ? Gen_MELA_Angles[3] : 999")

    # df = df.Define("Gen_cos_1_S", "PDGTest == 3 ? Gen_MELA_Angles[1] : 999")
    # df = df.Define("Gen_cos_2_S", "PDGTest == 3 ? Gen_MELA_Angles[2] : 999")
    # df = df.Define("Gen_phi_S", "PDGTest == 3 ? Gen_MELA_Angles[3] : 999")

    # df = df.Define("Gen_cos_1_C", "PDGTest == 4 ? Gen_MELA_Angles[1] : 999")
    # df = df.Define("Gen_cos_2_C", "PDGTest == 4 ? Gen_MELA_Angles[2] : 999")
    # df = df.Define("Gen_phi_C", "PDGTest == 4 ? Gen_MELA_Angles[3] : 999")

    # df = df.Define("Gen_cos_1_B", "PDGTest == 5 ? Gen_MELA_Angles[1] : 999")
    # df = df.Define("Gen_cos_2_B", "PDGTest == 5 ? Gen_MELA_Angles[2] : 999")
    # df = df.Define("Gen_phi_B", "PDGTest == 5 ? Gen_MELA_Angles[3] : 999")



    df = df.Define("Gen_cos_1", "Gen_MELA_Angles[1]")
    df = df.Define("Gen_cos_2", "Gen_MELA_Angles[2]")
    df = df.Define("Gen_phi", "Gen_MELA_Angles[3]")
    df = df.Define("Gen_mVstar", "Gen_MELA_Angles[5]")
    df = df.Define("Gen_mV", "Gen_MELA_Angles[6]")


    df = df.Define("ghz1Pair", 'FCCAnalyses::JHUfunctions::makeCouplingPairs("ghz1", 2, 0)')
    df = df.Define("SMVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz1Pair})')
    

    df = df.Define("ghz4Pair", 'FCCAnalyses::JHUfunctions::makeCouplingPairs("ghz4", 0.864922411, 0)')
    df = df.Define("Negghz4Pair", 'FCCAnalyses::JHUfunctions::makeCouplingPairs("ghz4", -0.864922411, 0)')
    df = df.Define("BSMVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz4Pair})')
    
    df = df.Define("MixtureVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz1Pair, ghz4Pair})')
    df = df.Define("NegMixtureVec", 'FCCAnalyses::JHUfunctions::createCouplingVector({ghz1Pair, Negghz4Pair})')

    
    
    # EXAMPLE OF APPENDING HISTOS FROM JET STUFF TO NORMAL OUTPUT
    for x in range(0, 4):
        results.append(df.Histo1D(("jet{}_scoreQ{}".format(x, ""), "", *bins_jet_score),"jet{}_scoreQ{}".format(x, "")))
        #results.append(df.Histo1D(("jet{}_scoreU{}".format(x, ""), "", *bins_count),"jet{}_scoreU{}".format(x, "")))
        #results.append(df.Histo1D(("jet{}_scoreTAU{}".format(x, ""), "", *bins_count),"jet{}_scoreTAU{}".format(x, "")))
        results.append(df.Histo1D(("jet{}_scoreB{}".format(x, ""), "", *bins_jet_score),"jet{}_scoreB{}".format(x, "")))
        results.append(df.Histo1D(("jet{}_scoreC{}".format(x, ""), "", *bins_jet_score),"jet{}_scoreC{}".format(x, "")))
        results.append(df.Histo1D(("jet{}_scoreS{}".format(x, ""), "", *bins_jet_score),"jet{}_scoreS{}".format(x, "")))
        results.append(df.Histo1D(("jet{}_scoreG{}".format(x, ""), "", *bins_jet_score),"jet{}_scoreG{}".format(x, "")))
    
   

    if do_weights:
        if dataset in sigProcs:
            df = df.Define("BSMWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, qTLV, qBarTLV, BSMVec)')
            
            df = df.Define("SMWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, qTLV, qBarTLV, SMVec)')
            df = df.Define("MixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, qTLV, qBarTLV, MixtureVec)')
            df = df.Define("NegMixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, higgsMCTLV, LHEAssociatedParticleId, qTLV, qBarTLV, NegMixtureVec)')

            #Normalizing Weights: 
            df = df.Redefine("BSMWeights", "BSMWeights/SMWeights")
            df = df.Redefine("MixtureWeights", "MixtureWeights/SMWeights")
            df = df.Redefine("NegMixtureWeights", "NegMixtureWeights/SMWeights")
            
            df = df.Define("ScaledUpBSMWeights", "BSMWeights*8.07")
            #
            df = df.Define("InterferenceWeights", "MixtureWeights - BSMWeights - 1")
        

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
    results.append(df.Histo1D(("daughter_higgs", "", *bins_pdgid), "daughter_higgs"))
    results.append(df.Histo1D(("daughter_higgs0", "", *bins_pdgid), "daughter_higgs0"))
    results.append(df.Histo1D(("HiggsIdx", "", *bins_count), "higgs_MC"))
    results.append(df.Histo1D(("higgs_mass_MC", "", *bins_recoil), "higgs_mass_MC"))
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
    results.append(df.Histo1D(("qBarPhi", "", *bins_phi), "qBarPhi"))

    results.append(df.Histo1D(("qPDG", "", *bins_pdgid), "qPDG"))
    results.append(df.Histo1D(("PDGTest", "", *bins_pdgid), "PDGTest"))
    results.append(df.Histo1D(("qE", "", *bins_p_mu), "qE"))
    results.append(df.Histo1D(("qPhi", "", *bins_phi), "qPhi"))

  
    # results.append(df.Histo1D(("ParticleZeroGenStatus", "", *bins_count), "ParticleZeroGenStatus"))
    # results.append(df.Histo1D(("ParticleZeroSimStatus", "", *bins_count), "ParticleZeroSimStatus"))
    # results.append(df.Histo1D(("ParticleZeroPDG", "", *bins_pdgid), "ParticleZeroPDG"))
    # results.append(df.Histo1D(("ParticleZeroE", "", *bins_p_mu), "ParticleZeroE"))
    # results.append(df.Histo1D(("ParticleZeroPz", "", *bins_p_mubeeg), "ParticleZeroPz"))
    # results.append(df.Histo1D(("ParticleZeroDaus", "", *bins_pdgid), "ParticleZeroDaus"))
    # results.append(df.Histo1D(("ParticleZeroDausIdx", "", *bins_pdgid), "ParticleZeroDausIdx"))


    # results.append(df.Histo1D(("ParticleOneGenStatus", "", *bins_count), "ParticleOneGenStatus"))
    # results.append(df.Histo1D(("ParticleOneSimStatus", "", *bins_count), "ParticleOneSimStatus"))
    # results.append(df.Histo1D(("ParticleOnePDG", "", *bins_pdgid), "ParticleOnePDG"))
    # results.append(df.Histo1D(("ParticleOneE", "", *bins_p_mu), "ParticleOneE"))
    # results.append(df.Histo1D(("ParticleOnePz", "", *bins_p_mubeeg), "ParticleOnePz"))
    # results.append(df.Histo1D(("ParticleOneDaus", "", *bins_pdgid), "ParticleOneDaus"))
    # results.append(df.Histo1D(("ParticleOneDausIdx", "", *bins_pdgid), "ParticleOneDausIdx"))

    # results.append(df.Histo1D(("ParticleTwoGenStatus", "", *bins_count), "ParticleTwoGenStatus"))
    # results.append(df.Histo1D(("ParticleTwoSimStatus", "", *bins_count), "ParticleTwoSimStatus"))
    # results.append(df.Histo1D(("ParticleTwoPDG", "", *bins_pdgid), "ParticleTwoPDG"))
    # results.append(df.Histo1D(("ParticleTwoE", "", *bins_p_mu), "ParticleTwoE"))
    # results.append(df.Histo1D(("ParticleTwoPz", "", *bins_p_mubeeg), "ParticleTwoPz"))
    # results.append(df.Histo1D(("ParticleTwoDaus", "", *bins_pdgid), "ParticleTwoDaus"))
    # results.append(df.Histo1D(("ParticleTwoDausIdx", "", *bins_pdgid), "ParticleTwoDausIdx"))

    # results.append(df.Histo1D(("ParticleThreeGenStatus", "", *bins_count), "ParticleThreeGenStatus"))
    # results.append(df.Histo1D(("ParticleThreeSimStatus", "", *bins_count), "ParticleThreeSimStatus"))
    # results.append(df.Histo1D(("ParticleThreePDG", "", *bins_pdgid), "ParticleThreePDG"))
    # results.append(df.Histo1D(("ParticleThreeE", "", *bins_p_mu), "ParticleThreeE"))
    # results.append(df.Histo1D(("ParticleThreePz", "", *bins_p_mubeeg), "ParticleThreePz"))
    # results.append(df.Histo1D(("ParticleThreeDaus", "", *bins_pdgid), "ParticleThreeDaus"))
    # results.append(df.Histo1D(("ParticleThreeDausIdx", "", *bins_pdgid), "ParticleThreeDausIdx"))

    # results.append(df.Histo1D(("ParticleSixGenStatus", "", *bins_count), "ParticleSixGenStatus"))
    # results.append(df.Histo1D(("ParticleSixSimStatus", "", *bins_count), "ParticleSixSimStatus"))
    # results.append(df.Histo1D(("ParticleSixPDG", "", *bins_pdgid), "ParticleSixPDG"))
    # results.append(df.Histo1D(("ParticleSixE", "", *bins_p_mu), "ParticleSixE"))
    # results.append(df.Histo1D(("ParticleSixPz", "", *bins_p_mubeeg), "ParticleSixPz"))
    # results.append(df.Histo1D(("ParticleSixDaus", "", *bins_pdgid), "ParticleSixDaus"))
    # results.append(df.Histo1D(("ParticleSixDausIdx", "", *bins_pdgid), "ParticleSixDausIdx"))

    # results.append(df.Histo1D(("ParticleSevenGenStatus", "", *bins_count), "ParticleSevenGenStatus"))
    # results.append(df.Histo1D(("ParticleSevenSimStatus", "", *bins_count), "ParticleSevenSimStatus"))
    # results.append(df.Histo1D(("ParticleSevenPDG", "", *bins_pdgid), "ParticleSevenPDG"))
    # results.append(df.Histo1D(("ParticleSevenE", "", *bins_p_mu), "ParticleSevenE"))
    # results.append(df.Histo1D(("ParticleSevenPz", "", *bins_p_mubeeg), "ParticleSevenPz"))
    # results.append(df.Histo1D(("ParticleSevenDaus", "", *bins_pdgid), "ParticleSevenDaus"))
    # results.append(df.Histo1D(("ParticleSevenDausIdx", "", *bins_pdgid), "ParticleSevenDausIdx"))


    # define cutflow variables
    for i in range(0, 20):
        df = df.Define("cut%d"%i, "%d"%i)
        df = df.Define("bb_cut%d"%i, "%d"%i)
        df = df.Define("Nbb_cut%d"%i, "%d"%i)

    df = df.Define("nominal_weight", "1.0")

    #Get a list of all muons
    #df = df.Define("muons", "FCCAnalyses::ReconstructedParticle::get(Muon0, ReconstructedParticles)")
    #df = df.Define("muons_p", "FCCAnalyses::ReconstructedParticle::get_p(muons)[0]")

    #df = df.Define("electrons", "FCCAnalyses::ReconstructedParticle::get(Electron0, ReconstructedParticles)")
    #df = df.Define("electrons_p", "FCCAnalyses::ReconstructedParticle::get_p(electrons)[0]")


    results.append(df.Histo1D(("muons_p", "", *bins_p_ll), "muons_p"))
    results.append(df.Histo1D(("electrons_p", "", *bins_p_ll), "electrons_p"))
    df = df.Define("muons_no", "FCCAnalyses::ReconstructedParticle::get_n(muons)")
    df = df.Define("electrons_no", "FCCAnalyses::ReconstructedParticle::get_n(electrons)")

    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut0", "nominal_weight"))

    df_bb = df
    df_Nbb = df 

    

    #INITIAL NO. OF EVENTS:
    results.append(df_bb.Histo1D(("bb_cutFlow", "", *bins_count), "cut0", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("Nbb_cutFlow", "", *bins_count), "cut0", "nominal_weight"))

    #########################################################################################################
    ### Cut 1: Electron Veto                                                            #
    #########################################################################################################
    df = df.Filter("electrons_no <= 2")
    df = df.Filter("electrons_p < 20")

    df_bb = df_bb.Filter("electrons_no <= 2")
    df_bb = df_bb.Filter("electrons_p < 20")

    df_Nbb = df_Nbb.Filter("electrons_no <= 2")
    df_Nbb = df_Nbb.Filter("electrons_p < 20")

    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut1", "nominal_weight"))
    results.append(df_bb.Histo1D(("bb_cutFlow", "", *bins_count), "bb_cut1", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("Nbb_cutFlow", "", *bins_count), "Nbb_cut1", "nominal_weight"))

    #########################################################################################################
    ### Cut2: Muon Veto                                                                  #
    #########################################################################################################
    df = df.Filter("muons_no <= 2")
    df = df.Filter("muons_p < 20")
    results.append(df.Histo1D(("cutFlow", "", *bins_count), "cut2", "nominal_weight"))
    results.append(df_bb.Histo1D(("bb_cutFlow", "", *bins_count), "bb_cut2", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("Nbb_cutFlow", "", *bins_count), "Nbb_cut2", "nominal_weight"))





    


    
    





  
  

    #df = df.Define("RPS_no_mu", "FCCAnalyses::ReconstructedParticle::remove(ReconstructedParticles, muons)")
   
#Deprecated Jet Building 
    # #Build Jets: 
    # df= df.Define("RP_px", "FCCAnalyses::ReconstructedParticle::get_px(ReconstructedParticles)")
    # df= df.Define("RP_py", "FCCAnalyses::ReconstructedParticle::get_py(ReconstructedParticles)")
    # df= df.Define("RP_pz", "FCCAnalyses::ReconstructedParticle::get_pz(ReconstructedParticles)")
    # df = df.Define("RP_e", "FCCAnalyses::ReconstructedParticle::get_e(ReconstructedParticles)")
    # df = df.Define("pseudo_jets", "FCCAnalyses::JetClusteringUtils::set_pseudoJets(RP_px, RP_py, RP_pz, RP_e)")


    # #Do Jet Clustering: 
    # df = df.Define("clustered_jets", "JetClustering::clustering_ee_kt(3,6,0,10)(pseudo_jets)")

    # df = df.Define("jets", "FCCAnalyses::JetClusteringUtils::get_pseudoJets(clustered_jets)")
    # df = df.Define("jetconstituents", "FCCAnalyses::JetClusteringUtils::get_constituents(clustered_jets)") 
    # df = df.Define("firstJet", "jetconstituents[0]")
    # results.append(df.Histo1D(("jetconstituents", "", *bins_count), "firstJet"))
    # df = df.Define("jets_e", "FCCAnalyses::JetClusteringUtils::get_e(jets)")
    # df = df.Define("jets_px", "FCCAnalyses::JetClusteringUtils::get_px(jets)")
    # df = df.Define("jets_py", "FCCAnalyses::JetClusteringUtils::get_py(jets)")
    # df = df.Define("jets_pz", "FCCAnalyses::JetClusteringUtils::get_pz(jets)")
    # df = df.Define("jets_phi", "FCCAnalyses::JetClusteringUtils::get_phi(jets)")
    # df = df.Define("jets_pt", "FCCAnalyses::JetClusteringUtils::get_pt(jets)")
    # df = df.Define("jets_m", "FCCAnalyses::JetClusteringUtils::get_m(jets)")

    # #df = df.Filter("jets_pt > 20")
    

    # # convert jets to LorentzVectors 
    # df = df.Define("jets_tlv", "FCCAnalyses::JHUfunctions::makeLorentzVectors(jets_px, jets_py, jets_pz, jets_e)")

    for x in range(0,4): 
        #df = df.Define("jet{}_tlv".format(x), "ROOT::Math::PxPyPzEVector(jet{}_px, jet{}_py, jet{}_pz, jet{}_e)".format(x,x,x,x))
        df = df.Define("jet{}_tlv".format(x), "TLorentzVector(jet{}_px, jet{}_py, jet{}_pz, jet{}_e)".format(x,x,x,x))
    
    df = df.Define("jets_tlv", "ROOT::VecOps::RVec<TLorentzVector>{jet0_tlv, jet1_tlv, jet2_tlv, jet3_tlv}")

    #attempting to do truth matching 
    #df = df.Define("jets_truth", "FCCAnalyses::JHUfunctions::jetTruthFinder(jetconstituents, ReconstructedParticles, Particle, MCRecoAssociations1)") # returns best-matched PDG ID of the jets

    #df = df.Define("RP_MC_index", "ReconstructedParticle2MC::getRP2MC_index(MCRecoAssociations0, MCRecoAssociations1, ReconstructedParticles)")
    #results.append(df.Histo1D(("RP_MC_index", "", *bins_count), "RP_MC_index"))
   

    
    
    df = df.Define("Best_Jets_Output", "FCCAnalyses::JHUfunctions::get_best_jet_pair(91.2, 125.0, 240, jets_tlv, VectorOfScoreVectors)")
    
    

    df = df.Define("Best_Jets_Result", "Best_Jets_Output.first")

    df = df.Define("JetIdxPair", "Best_Jets_Output.second")

    df = df.Define("Jet1Idx", " static_cast<size_t>(JetIdxPair.first)")
    df = df.Define("Jet2Idx", " static_cast<size_t>(JetIdxPair.second)")

    df = df.Define("Best_Jets_PDG1", "FCCAnalyses::JHUfunctions::PDGFromScoreVec(VectorOfScoreVectors[Jet1Idx])")
    df = df.Define("Best_Jets_PDG2", "FCCAnalyses::JHUfunctions::PDGFromScoreVec(VectorOfScoreVectors[Jet2Idx])")


    df = df.Define("Best_Jets1_ScoreQ", 'VectorOfScoreVectors[Jet1Idx][0]')
    df = df.Define("Best_Jets1_ScoreB", 'VectorOfScoreVectors[Jet1Idx][1]')
    df = df.Define("Best_Jets1_ScoreC", 'VectorOfScoreVectors[Jet1Idx][2]')
    df = df.Define("Best_Jets1_ScoreS", 'VectorOfScoreVectors[Jet1Idx][3]')
    df = df.Define("Best_Jets1_ScoreG", 'VectorOfScoreVectors[Jet1Idx][4]')

    results.append(df.Histo1D(("Best_Jets1_ScoreQ", "", *bins_jet_score), "Best_Jets1_ScoreQ"))
    results.append(df.Histo1D(("Best_Jets1_ScoreB", "", *bins_jet_score), "Best_Jets1_ScoreB"))
    results.append(df.Histo1D(("Best_Jets1_ScoreC", "", *bins_jet_score), "Best_Jets1_ScoreC"))
    results.append(df.Histo1D(("Best_Jets1_ScoreS", "", *bins_jet_score), "Best_Jets1_ScoreS"))
    results.append(df.Histo1D(("Best_Jets1_ScoreG", "", *bins_jet_score), "Best_Jets1_ScoreG"))


    df = df.Define("Best_Jets2_ScoreQ", "VectorOfScoreVectors[Jet2Idx][0]")
    df = df.Define("Best_Jets2_ScoreB", "VectorOfScoreVectors[Jet2Idx][1]")
    df = df.Define("Best_Jets2_ScoreC", "VectorOfScoreVectors[Jet2Idx][2]")
    df = df.Define("Best_Jets2_ScoreS", "VectorOfScoreVectors[Jet2Idx][3]")
    df = df.Define("Best_Jets2_ScoreG", "VectorOfScoreVectors[Jet2Idx][4]")

    results.append(df.Histo1D(("Best_Jets2_ScoreQ", "", *bins_jet_score), "Best_Jets2_ScoreQ"))
    results.append(df.Histo1D(("Best_Jets2_ScoreB", "", *bins_jet_score), "Best_Jets2_ScoreB"))
    results.append(df.Histo1D(("Best_Jets2_ScoreC", "", *bins_jet_score), "Best_Jets2_ScoreC"))
    results.append(df.Histo1D(("Best_Jets2_ScoreS", "", *bins_jet_score), "Best_Jets2_ScoreS"))
    results.append(df.Histo1D(("Best_Jets2_ScoreG", "", *bins_jet_score), "Best_Jets2_ScoreG"))

    results.append(df.Histo2D(("Jet1_B_vs_Q", "", *(bins_jet_score + bins_jet_score)), "Best_Jets1_ScoreQ", "Best_Jets1_ScoreB"))
    results.append(df.Histo2D(("Jet1_C_vs_Q", "", *(bins_jet_score + bins_jet_score)), "Best_Jets1_ScoreQ", "Best_Jets1_ScoreC"))
    results.append(df.Histo2D(("Jet1_S_vs_Q", "", *(bins_jet_score + bins_jet_score)), "Best_Jets1_ScoreQ", "Best_Jets1_ScoreS"))
    results.append(df.Histo2D(("Jet1_G_vs_Q", "", *(bins_jet_score + bins_jet_score)), "Best_Jets1_ScoreQ", "Best_Jets1_ScoreG"))

    results.append(df.Histo2D(("Jet2_B_vs_Q", "", *(bins_jet_score + bins_jet_score)), "Best_Jets2_ScoreQ", "Best_Jets2_ScoreB"))
    results.append(df.Histo2D(("Jet2_C_vs_Q", "", *(bins_jet_score + bins_jet_score)), "Best_Jets2_ScoreQ", "Best_Jets2_ScoreC"))
    results.append(df.Histo2D(("Jet2_S_vs_Q", "", *(bins_jet_score + bins_jet_score)), "Best_Jets2_ScoreQ", "Best_Jets2_ScoreS"))
    results.append(df.Histo2D(("Jet2_G_vs_Q", "", *(bins_jet_score + bins_jet_score)), "Best_Jets2_ScoreQ", "Best_Jets2_ScoreG"))



    results.append(df.Histo1D(("Best_Jets_PDG1", "", *bins_pdgid), "Best_Jets_PDG1"))
    results.append(df.Histo1D(("Best_Jets_PDG2", "", *bins_pdgid), "Best_Jets_PDG2"))
    results.append(df.Histo2D(("Jet1PDG_vs_Jet2PDG", "", *(bins_pdgid + bins_pdgid)), "Best_Jets_PDG1", "Best_Jets_PDG2"))

    df = df.Define("QScoreSum", "Best_Jets1_ScoreQ + Best_Jets2_ScoreQ")
    results.append(df.Histo1D(("QScoreSum_nmone", "", *bins_jet_scoreSum), "QScoreSum"))

    df = df.Define("BScoreSum", "Best_Jets1_ScoreB + Best_Jets2_ScoreB")
    results.append(df.Histo1D(("BScoreSum_nmone", "", *bins_jet_scoreSum), "BScoreSum"))

    df = df.Define("CScoreSum", "Best_Jets1_ScoreC + Best_Jets2_ScoreC")
    results.append(df.Histo1D(("CScoreSum_nmone", "", *bins_jet_scoreSum), "CScoreSum"))

    df = df.Define("SScoreSum", "Best_Jets1_ScoreS + Best_Jets2_ScoreS")
    results.append(df.Histo1D(("SScoreSum_nmone", "", *bins_jet_scoreSum), "SScoreSum"))

    df = df.Define("GScoreSum", "Best_Jets1_ScoreG + Best_Jets2_ScoreG")
    results.append(df.Histo1D(("GScoreSum_nmone", "", *bins_jet_scoreSum), "GScoreSum"))

    df = df.Define("Z_tlv", "Best_Jets_Result[0]")
    df = df.Define("Z_mass", "Z_tlv.M()")
    #df = df.Define("Z_mass", "(jets_tlv[0] + jets_tlv[1]).M()")
    df = df.Define("Z_pt","Z_tlv.Pt()" )
    df = df.Define("Z_p", "Z_tlv.P()")
    df = df.Define("Jets_No", "jets_tlv.size()")

    df = df.Define("recoil_tlv", "Best_Jets_Result[1]")
    df = df.Define("recoil_mass", "recoil_tlv.M()")

    df = df.Define("recoil_mass_corrected", "recoil_mass + Z_mass - 91.187")

    df = df.Define("jetsTruthPDG", "FCCAnalyses::JHUfunctions::jetTruthFinder(jets_tlv, Particle)")
    df = df.Define("BestJetsTruth", "FCCAnalyses::JHUfunctions::BestJetTruthFinder(ROOT::VecOps::RVec<TLorentzVector>{Best_Jets_Result[2], Best_Jets_Result[3]}, Particle, electronDausIdx[1], electronDausIdx[0])")
    df = df.Define("BestJetsTruthPDG", "BestJetsTruth.first")
    df = df.Define("BestJetsTruthZ", "BestJetsTruth.second")
    results.append(df.Histo1D(("Best_Jets_TruthPDG_BeforeCuts", "", *bins_pdgid), "BestJetsTruthPDG"))
    results.append(df.Histo1D(("Best_Jets_TruthZ_BeforeCuts", "", *bins_binary), "BestJetsTruthZ"))   

    df = df.Define("chi", "sqrt( pow((Z_mass - 91.187) , 2) + pow((recoil_mass - 125), 2))")
    df = df.Define("W_chi", "sqrt( pow((Z_mass - 80.38) , 2) + pow((recoil_mass - 80.38), 2))")
    df = df.Define("Z_chi", "sqrt( pow((Z_mass - 91.2) , 2) + pow( (recoil_mass - 91.2), 2))")


    #Making Reco-Level Angles 
    df = df.Define("ideal_positron_tlv", "FCCAnalyses::JHUfunctions::makePositronTlv()")
    df = df.Define("ideal_electron_tlv", "FCCAnalyses::JHUfunctions::makeElectronTlv()")

   

    df = df.Redefine("Best_Jets_PDG1", "qBarPhi < 0 ? Best_Jets_PDG1 : -Best_Jets_PDG1")
    df = df.Redefine("Best_Jets_PDG2", "qBarPhi < 0 ? -Best_Jets_PDG2 : Best_Jets_PDG2")

    df = df.Define("Reco_MELA_Angles", "FCCAnalyses::JHUfunctions::MELAAngles(ideal_electron_tlv, 11, ideal_positron_tlv, -11, Best_Jets_Result[2], Best_Jets_PDG1, Best_Jets_Result[3], Best_Jets_PDG2)")
    df = df.Define("cos_1", "Reco_MELA_Angles[1]")
    df = df.Define("cos_2", "Reco_MELA_Angles[2]")
    df = df.Define("phi", "Reco_MELA_Angles[3]")

#REMEMBER TO UNCOMMENT
    if do_weights: 
        if dataset in sigProcs: 
        #Making Reco-Level probabilities for discriminants 
            df = df.Define("RecoSMWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, recoil_tlv, LHEAssociatedParticleId, Best_Jets_Result[2], Best_Jets_Result[3], SMVec)')
            df = df.Define("RecoBSMWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, recoil_tlv, LHEAssociatedParticleId, Best_Jets_Result[2], Best_Jets_Result[3], BSMVec)')
            df = df.Define("RecoMixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, recoil_tlv, LHEAssociatedParticleId, Best_Jets_Result[2], Best_Jets_Result[3], MixtureVec)')
            df = df.Define("RecoNegMixtureWeights", 'FCCAnalyses::JHUfunctions::Weights(LHEDaughterId, recoil_tlv, LHEAssociatedParticleId, Best_Jets_Result[2], Best_Jets_Result[3], NegMixtureVec)')
            df = df.Define("RecoInterferenceWeights", 'RecoMixtureWeights - RecoSMWeights - RecoBSMWeights')
            df = df.Define("D_0Minus", 'RecoSMWeights/ (RecoSMWeights + RecoBSMWeights)')
            df = df.Define("D_CP", 'RecoInterferenceWeights/(2*sqrt(RecoSMWeights*RecoBSMWeights))')

    
    
    

    


    #############################
    ### Cut 3: Splitting on B-Score
    #############################
    df_bb = df.Filter("BScoreSum >= 1.7")
    # results.append(df_bb.Histo1D(("bb_cutFlow", "", *bins_count), "bb_cut3", "nominal_weight"))
    results.append(df_bb.Histo1D(("bb_cutFlow", "", *bins_count), "bb_cut3", "nominal_weight"))

    df_Nbb = df.Filter("BScoreSum < 1.7")
    results.append(df_Nbb.Histo1D(("Nbb_cutFlow", "", *bins_count), "Nbb_cut3", "nominal_weight"))
    
    # results.append(df_Nbb.Histo1D(("Z_mass_nmone_NHCB", "", *bins_m_Z), "Z_mass", "nominal_weight"))
    # results.append(df_Nbb.Histo1D(("Z_p_nmone_NHCB", "", *bins_p_ll), "Z_p"))
    # results.append(df_Nbb.Histo1D(("recoil_mass_nmone_NHCB", "", *bins_m_Z), "recoil_mass"))
    # results.append(df_Nbb.Histo1D(("vis_theta_nmone_NHCB", "", *bins_theta), "vis_theta", "nominal_weight"))

   


    ####################
    ### Cut 4: Z-Mass
    ####################
    results.append(df_bb.Histo1D(("Z_mass_nmone_bb", "", *bins_m_Z), "Z_mass", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("Z_mass_nmone_Nbb", "", *bins_m_Z), "Z_mass", "nominal_weight"))

    df_bb = df_bb.Filter("Z_mass > 80 && Z_mass < 100")
    df_Nbb = df_Nbb.Filter("Z_mass > 80 && Z_mass < 100")
    results.append(df_bb.Histo1D(("cutFlow", "", *bins_count), "cut3", "nominal_weight"))
    results.append(df_bb.Histo1D(("bb_cutFlow", "", *bins_count), "bb_cut4", "nominal_weight"))

    results.append(df_Nbb.Histo1D(("cutFlow", "", *bins_count), "cut3", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("Nbb_cutFlow", "", *bins_count), "Nbb_cut4", "nominal_weight"))

    ####################
    ### Cut 5: Z-Momentum  
    ####################
    results.append(df_bb.Histo1D(("Z_p_nmone_bb", "", *bins_p_ll), "Z_p"))
    results.append(df_Nbb.Histo1D(("Z_p_nmone_Nbb", "", *bins_p_ll), "Z_p"))
    df_bb = df_bb.Filter("Z_p >= 20 && Z_p <= 60")
    df_Nbb = df_Nbb.Filter("Z_p >= 40 && Z_p <= 60")

    results.append(df_bb.Histo1D(("cutFlow", "", *bins_count), "cut4", "nominal_weight"))
    results.append(df_bb.Histo1D(("bb_cutFlow", "", *bins_count), "bb_cut5", "nominal_weight"))

    results.append(df_Nbb.Histo1D(("cutFlow", "", *bins_count), "cut4", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("Nbb_cutFlow", "", *bins_count), "Nbb_cut5", "nominal_weight"))

    ####################
    ### Cut 6 : recoil mass: 
    #################### 
    results.append(df_bb.Histo1D(("recoil_mass_nmone_bb", "", *bins_m_Z), "recoil_mass"))
    results.append(df_Nbb.Histo1D(("recoil_mass_nmone_Nbb", "", *bins_m_Z), "recoil_mass_corrected"))
    df_bb = df_bb.Filter("recoil_mass > 110 && recoil_mass < 138")
    df_Nbb = df_Nbb.Filter("recoil_mass > 120 && recoil_mass < 140")
    results.append(df_bb.Histo1D(("cutFlow", "", *bins_count), "cut5", "nominal_weight"))
    results.append(df_bb.Histo1D(("bb_cutFlow", "", *bins_count), "bb_cut6", "nominal_weight"))

    results.append(df_Nbb.Histo1D(("cutFlow", "", *bins_count), "cut5", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("Nbb_cutFlow", "", *bins_count), "Nbb_cut6", "nominal_weight"))

    ####################
    ### Cut 7: Visible Energy and Visible Mass 
    ####################
    results.append(df_bb.Histo1D(("vis_theta_nmone_bb", "", *bins_theta), "vis_theta", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("vis_theta_nmone_Nbb", "", *bins_theta), "vis_theta", "nominal_weight"))

    results.append(df_bb.Histo1D(("vis_E_nmone_bb", "", *bins_E), "vis_E", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("vis_E_nmone_Nbb", "", *bins_E), "vis_E", "nominal_weight"))

    results.append(df_bb.Histo1D(("vis_M_nmone_bb", "", *bins_E), "vis_M", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("vis_M_nmone_Nbb", "", *bins_E), "vis_M", "nominal_weight"))
    df_bb = df_bb.Filter("vis_M > 150")
    df_bb = df_bb.Filter("vis_E > 150")
    df_bb = df_bb.Filter("vis_theta > 0.1415 && vis_theta < 3.0")

    df_Nbb = df_Nbb.Filter("vis_M > 150")
    df_Nbb = df_Nbb.Filter("vis_E > 150")
    df_Nbb = df_Nbb.Filter("vis_theta > 0.1415 && vis_theta < 3.0")


    results.append(df_bb.Histo1D(("cutFlow", "", *bins_count), "cut6", "nominal_weight"))
    results.append(df_bb.Histo1D(("bb_cutFlow", "", *bins_count), "bb_cut7", "nominal_weight"))

    results.append(df_Nbb.Histo1D(("cutFlow", "", *bins_count), "cut6", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("Nbb_cutFlow", "", *bins_count), "Nbb_cut7", "nominal_weight"))


    for x in range(1, 9):
        results.append(df_bb.Histo1D(("d_{}{}_nmone".format(x, x+1), "", *bins_dij), "d_{}{}".format(x,x+1)))


    ####################
    ### Cut 8: WW and ZZ Rejection 
    #################### 
  
    results.append(df_Nbb.Histo1D(("chi_nmone_Nbb", "", *bins_m_Z), "chi"))
    results.append(df_Nbb.Histo1D(("W_chi_nmone_Nbb", "", *bins_m_Z), "W_chi"))
    results.append(df_Nbb.Histo1D(("Z_chi_nmone_Nbb", "", *bins_m_Z), "Z_chi"))
    # # results.append(df_bb.Histo1D(("chi", "", *bins_m_Z), "chi"))
    results.append(df_bb.Histo1D(("chi_nmone_bb", "", *bins_m_Z), "chi"))
    results.append(df_bb.Histo1D(("W_chi_nmone_bb", "", *bins_m_Z), "W_chi"))
    results.append(df_bb.Histo1D(("Z_chi_nmone_bb", "", *bins_m_Z), "Z_chi"))
    df_bb = df_bb.Filter("chi < 10")
    df_bb = df_bb.Filter("W_chi > 10")
    df_bb = df_bb.Filter("Z_chi > 10")

    df_Nbb = df_Nbb.Filter("chi < 10")
    df_Nbb = df_Nbb.Filter("W_chi > 10")
    df_Nbb = df_Nbb.Filter("Z_chi > 10")
    results.append(df_bb.Histo1D(("cutFlow", "", *bins_count), "cut7", "nominal_weight"))
    results.append(df_bb.Histo1D(("bb_cutFlow", "", *bins_count), "bb_cut8", "nominal_weight"))

    results.append(df_Nbb.Histo1D(("cutFlow", "", *bins_count), "cut7", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("Nbb_cutFlow", "", *bins_count), "Nbb_cut8", "nominal_weight"))
    
    
    

    #Number of each type of jet before score cut, just going off of first good jet for now:
    # df_bb = df_bb.Define("Q_cut0", "Best_Jets_PDG1 == 1 ? 0 : 999")
    # results.append(df_bb.Histo1D(("Q_cutflow", "", *bins_count), "Q_cut0"))

    # df_bb = df_bb.Define("B_cut0", "Best_Jets_PDG1 == 5 ? 0 : 999")
    # results.append(df_bb.Histo1D(("B_cutflow", "", *bins_count), "B_cut0"))

    # df_bb = df_bb.Define("C_cut0", "Best_Jets_PDG1 == 4 ? 0 : 999")
    # results.append(df_bb.Histo1D(("C_cutflow", "", *bins_count), "C_cut0"))

    # df_bb = df_bb.Define("S_cut0", "Best_Jets_PDG1 == 3 ? 0 : 999")
    # results.append(df_bb.Histo1D(("S_cutflow", "", *bins_count), "S_cut0"))

    # df_bb = df_bb.Define("G_cut0", "Best_Jets_PDG1 == 21 ? 0 : 999")
    # results.append(df_bb.Histo1D(("G_cutflow", "", *bins_count), "G_cut0"))


    

    ####################
    ### Cut 8: Jet Score (Flavor Specific)
    ####################
    # if jet_flavor == "qq": 
    #     df_bb = df_bb.Filter("Best_Jets1_ScoreQ > 0.01")
    #     df_bb = df_bb.Filter("Best_Jets2_ScoreQ > 0.01")
    #         #df_bb = df_bb.Filter("jet{}_scoreQ > 0.1".format(x))
    # if jet_flavor == "bb":
    #     df_bb = df_bb.Filter("(BScoreSum) >= 1.6")
    
    # if jet_flavor == "cc": 
    #     df_bb = df_bb.Filter("CScoreSum >= 1.0")
    # results.append(df_bb.Histo1D(("cutFlow", "", *bins_count), "cut8", "nominal_weight"))
   

  
    

    #Number of each type of jet after score cut:
    # df_bb = df_bb.Define("Q_cut1", "Best_Jets_PDG1 == 1 ? 1 : 999")
    # results.append(df_bb.Histo1D(("Q_cutflow", "", *bins_count), "Q_cut1"))

    # df_bb = df_bb.Define("B_cut1", "Best_Jets_PDG1 == 5 ? 1 : 999")
    # results.append(df_bb.Histo1D(("B_cutflow", "", *bins_count), "B_cut1"))

    # df_bb = df_bb.Define("C_cut1", "Best_Jets_PDG1 == 4 ? 1 : 999")
    # results.append(df_bb.Histo1D(("C_cutflow", "", *bins_count), "C_cut1"))

    # df_bb = df_bb.Define("S_cut1", "Best_Jets_PDG1 == 3 ? 1 : 999")
    # results.append(df_bb.Histo1D(("S_cutflow", "", *bins_count), "S_cut1"))

    # df_bb = df_bb.Define("G_cut1", "Best_Jets_PDG1 == 11 ? 1 : 999")
    # results.append(df_bb.Histo1D(("G_cutflow", "", *bins_count), "G_cut1")) 


   
    
        



    

    

    



    df_bb = df_bb.Define("cos_2_corrected", "cos_2 == 0 ? 999 : cos_2")
    df_Nbb = df_Nbb.Define("cos_2_corrected", "cos_2 == 0 ? 999 : cos_2")

     ################
    ### Cut 9: Cos_2
    ################
    results.append(df_bb.Histo1D(("cos_2_nmone_bb", "", *bins_cos), "cos_2", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("cos_2_nmone_Nbb", "", *bins_cos), "cos_2", "nominal_weight"))

    df_bb = df_bb.Filter("cos_2 > -0.99 && cos_2 < 0.99")
    df_bb = df_bb.Filter("cos_2 < 0 || cos_2 > 0")

    df_Nbb = df_Nbb.Filter("cos_2 > -0.99 && cos_2 < 0.99")
    df_Nbb = df_Nbb.Filter("cos_2 < 0 || cos_2 > 0")

    results.append(df_bb.Histo1D(("cutFlow", "", *bins_count), "cut8", "nominal_weight"))
    results.append(df_bb.Histo1D(("bb_cutFlow", "", *bins_count), "bb_cut9", "nominal_weight"))

    results.append(df_Nbb.Histo1D(("cutFlow", "", *bins_count), "cut8", "nominal_weight"))
    results.append(df_Nbb.Histo1D(("Nbb_cutFlow", "", *bins_count), "Nbb_cut9", "nominal_weight"))


    #################
    ### Cut 9: dij cuts 
    ##################
    # df_bb = df_bb.Filter("15000 < d_12 < 58000")
    # df_bb = df_bb.Filter("400 < d_23 < 18000")
    # df_bb = df_bb.Filter("100 < d_34 < 6000")
    # results.append(df_bb.Histo1D(("cutFlow", "", *bins_count), "cut9", "nominal_weight"))
    # results.append(df_bb.Histo1D(("bb_cutFlow", "", *bins_count), "bb_cut6", "nominal_weight"))

    # results.append(df_Nbb.Histo1D(("cutFlow", "", *bins_count), "cut9", "nominal_weight"))
    # results.append(df_Nbb.Histo1D(("Nbb_cutFlow", "", *bins_count), "Nbb_cut6", "nominal_weight"))
    
    

    

        
    


     
    #df_bb = df_bb.Filter("Z_pt < 61")
    # df_bb = df_bb.Define("zbuilder_result", f"FCCAnalyses::ZHfunctions::resonanceBuilder_mass_recoil(91.2, 125, 0.4, 240, {'true' if do_gen else 'false'})(jets, MCRecoAssociations0, MCRecoAssociations1, ReconstructedParticles, Particle, Particle0, Particle1)")
    # df_bb = df_bb.Define("zll", "ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>{zbuilder_result[0]}") # the Z
    # df_bb = df_bb.Define("zll_m", "FCCAnalyses::ReconstructedParticle::get_mass(zll)[0]")
    # df_bb = df_bb.Define("zll_recoil", "FCCAnalyses::ReconstructedParticle::recoilBuilder(240)(zll)")
    # df_bb = df_bb.Define("zll_recoil_m", "FCCAnalyses::ReconstructedParticle::get_mass(zll_recoil)[0]")



    #Make Histos 
    
    
  
    results.append(df_bb.Histo1D(("chi_bb", "", *bins_m_Z), "chi"))
    results.append(df_bb.Histo1D(("W_chi_bb", "", *bins_m_Z), "W_chi"))
    results.append(df_bb.Histo1D(("Z_chi_bb", "", *bins_m_Z), "Z_chi"))

    results.append(df_bb.Histo1D(("vis_E_bb", "", *bins_E), "vis_E"))
    results.append(df_Nbb.Histo1D(("vis_E_Nbb", "", *bins_E), "vis_E"))
    # results.append(df_bb.Histo1D(("Gen_cos_1_U", "", *bins_cos), "Gen_cos_1_U"))
    # results.append(df_bb.Histo1D(("Gen_cos_2_U", "", *bins_cos), "Gen_cos_2_U"))
    # results.append(df_bb.Histo1D(("Gen_phi_U", "", *bins_phiMELA), "Gen_phi_U"))

    # results.append(df_bb.Histo1D(("Gen_cos_1_D", "", *bins_cos), "Gen_cos_1_D"))
    # results.append(df_bb.Histo1D(("Gen_cos_2_D", "", *bins_cos), "Gen_cos_2_D"))
    # results.append(df_bb.Histo1D(("Gen_phi_D", "", *bins_phiMELA), "Gen_phi_D"))

    # results.append(df_bb.Histo1D(("Gen_cos_1_S", "", *bins_cos), "Gen_cos_1_S"))
    # results.append(df_bb.Histo1D(("Gen_cos_2_S", "", *bins_cos), "Gen_cos_2_S"))
    # results.append(df_bb.Histo1D(("Gen_phi_S", "", *bins_phiMELA), "Gen_phi_S"))

    # results.append(df_bb.Histo1D(("Gen_cos_1_C", "", *bins_cos), "Gen_cos_1_C"))
    # results.append(df_bb.Histo1D(("Gen_cos_2_C", "", *bins_cos), "Gen_cos_2_C"))
    # results.append(df_bb.Histo1D(("Gen_phi_C", "", *bins_phiMELA), "Gen_phi_C"))

    # results.append(df_bb.Histo1D(("Gen_cos_1_B", "", *bins_cos), "Gen_cos_1_B"))
    # results.append(df_bb.Histo1D(("Gen_cos_2_B", "", *bins_cos), "Gen_cos_2_B"))


    results.append(df_bb.Histo1D(("Gen_cos_1_bb", "", *bins_cos), "Gen_cos_1"))
    results.append(df_bb.Histo1D(("Gen_cos_2_bb", "", *bins_cos), "Gen_cos_2"))
    results.append(df_bb.Histo1D(("Gen_phi_bb", "", *bins_phiMELA), "Gen_phi"))
    
    results.append(df_bb.Histo1D(("cos_1_bb", "", *bins_cos), "cos_1"))
    results.append(df_bb.Histo1D(("cos_2_bb", "", *bins_cos), "cos_2"))
    results.append(df_bb.Histo1D(("cos_2_corrected_bb", "", *bins_cos), "cos_2_corrected"))
    results.append(df_bb.Histo1D(("phi_bb", "", *bins_phiMELA), "phi"))

    results.append(df_Nbb.Histo1D(("Gen_cos_1_Nbb", "", *bins_cos), "Gen_cos_1"))
    results.append(df_Nbb.Histo1D(("Gen_cos_2_Nbb", "", *bins_cos), "Gen_cos_2"))
    results.append(df_Nbb.Histo1D(("Gen_phi_Nbb", "", *bins_phiMELA), "Gen_phi"))
    
    results.append(df_Nbb.Histo1D(("cos_1_Nbb", "", *bins_cos), "cos_1"))
    results.append(df_Nbb.Histo1D(("cos_2_Nbb", "", *bins_cos), "cos_2"))
    results.append(df_Nbb.Histo1D(("cos_2_corrected_Nbb", "", *bins_cos), "cos_2_corrected"))
    results.append(df_Nbb.Histo1D(("phi_Nbb", "", *bins_phiMELA), "phi"))


    results.append(df_Nbb.Histo1D(("cos_1", "", *bins_cos), "cos_1"))
    results.append(df_Nbb.Histo1D(("cos_2", "", *bins_cos), "cos_2"))
    results.append(df_Nbb.Histo1D(("cos_2_corrected", "", *bins_cos), "cos_2_corrected"))
    results.append(df_Nbb.Histo1D(("phi", "", *bins_phiMELA), "phi"))

    results.append(df_bb.Histo1D(("cos_1", "", *bins_cos), "cos_1"))
    results.append(df_bb.Histo1D(("cos_2", "", *bins_cos), "cos_2"))
    results.append(df_bb.Histo1D(("cos_2_corrected", "", *bins_cos), "cos_2_corrected"))
    results.append(df_bb.Histo1D(("phi", "", *bins_phiMELA), "phi"))
    
    


    results.append(df_bb.Histo3D(("Angles_Template_SM", "", *(bins_cos_Template + bins_cos_Template + bins_phi_Template)), "cos_1", "cos_2_corrected", "phi", "nominal_weight"))
    results.append(df_Nbb.Histo3D(("Angles_Template_SM", "", *(bins_cos_Template + bins_cos_Template + bins_phi_Template)), "cos_1", "cos_2_corrected", "phi", "nominal_weight"))

    results.append(df_bb.Histo3D(("bb_Angles_Template_SM", "", *(bins_cos_Template + bins_cos_Template + bins_phi_Template)), "cos_1", "cos_2_corrected", "phi", "nominal_weight"))
    results.append(df_Nbb.Histo3D(("Nbb_Angles_Template_SM", "", *(bins_cos_Template + bins_cos_Template + bins_phi_Template)), "cos_1", "cos_2_corrected", "phi", "nominal_weight"))
    if do_weights: 
        #REMEMBER TO UNCOMMENT
        

        if dataset in sigProcs:
            results.append(df_bb.Histo1D(("Gen_cos_1_BSM", "", *bins_cos), "Gen_cos_1", "BSMWeights"))
            results.append(df_bb.Histo1D(("Gen_cos_2_BSM", "", *bins_cos), "Gen_cos_2", "BSMWeights"))
            results.append(df_bb.Histo1D(("Gen_phi_BSM", "", *bins_phiMELA), "Gen_phi", "BSMWeights"))
            results.append(df_Nbb.Histo1D(("Gen_cos_1_BSM", "", *bins_cos), "Gen_cos_1", "BSMWeights"))
            results.append(df_Nbb.Histo1D(("Gen_cos_2_BSM", "", *bins_cos), "Gen_cos_2", "BSMWeights"))
            results.append(df_Nbb.Histo1D(("Gen_phi_BSM", "", *bins_phiMELA), "Gen_phi", "BSMWeights"))

            results.append(df_bb.Histo1D(("Gen_cos_1_Int", "", *bins_cos), "Gen_cos_1", "InterferenceWeights"))
            results.append(df_bb.Histo1D(("Gen_cos_2_Int", "", *bins_cos), "Gen_cos_2", "InterferenceWeights"))
            results.append(df_bb.Histo1D(("Gen_phi_Int", "", *bins_phiMELA), "Gen_phi", "InterferenceWeights"))
            results.append(df_Nbb.Histo1D(("Gen_cos_1_Int", "", *bins_cos), "Gen_cos_1", "InterferenceWeights"))
            results.append(df_Nbb.Histo1D(("Gen_cos_2_Int", "", *bins_cos), "Gen_cos_2", "InterferenceWeights"))
            results.append(df_Nbb.Histo1D(("Gen_phi_Int", "", *bins_phiMELA), "Gen_phi", "InterferenceWeights"))

            # results.append(df_bb.Histo1D(("cos_1_SM", "", *bins_cos), "cos_1", "nominal_weight"))
            # results.append(df_bb.Histo1D(("cos_2_SM", "", *bins_cos), "cos_2", "nominal_weight"))
            # results.append(df_bb.Histo1D(("phi_SM", "", *bins_phiMELA), "phi", "nominal_weight"))

            results.append(df_bb.Histo1D(("cos_1_SM", "", *bins_cos), "cos_1", "SMWeights"))
            results.append(df_bb.Histo1D(("cos_2_SM", "", *bins_cos), "cos_2", "SMWeights"))
            results.append(df_bb.Histo1D(("phi_SM", "", *bins_phiMELA), "phi", "SMWeights"))


            results.append(df_bb.Histo1D(("cos_1_BSM", "", *bins_cos), "cos_1", "BSMWeights"))
            results.append(df_bb.Histo1D(("cos_2_BSM", "", *bins_cos), "cos_2", "BSMWeights"))
            results.append(df_bb.Histo1D(("phi_BSM", "", *bins_phiMELA), "phi", "BSMWeights"))

            results.append(df_bb.Histo1D(("cos_1_Int", "", *bins_cos), "cos_1", "InterferenceWeights"))
            results.append(df_bb.Histo1D(("cos_2_Int", "", *bins_cos), "cos_2", "InterferenceWeights"))
            results.append(df_bb.Histo1D(("phi_Int", "", *bins_phiMELA), "phi", "InterferenceWeights"))

            results.append(df_Nbb.Histo1D(("cos_1_SM", "", *bins_cos), "cos_1", "SMWeights"))
            results.append(df_Nbb.Histo1D(("cos_2_SM", "", *bins_cos), "cos_2", "SMWeights"))
            results.append(df_Nbb.Histo1D(("phi_SM", "", *bins_phiMELA), "phi", "SMWeights"))


            results.append(df_Nbb.Histo1D(("cos_1_BSM", "", *bins_cos), "cos_1", "BSMWeights"))
            results.append(df_Nbb.Histo1D(("cos_2_BSM", "", *bins_cos), "cos_2", "BSMWeights"))
            results.append(df_Nbb.Histo1D(("phi_BSM", "", *bins_phiMELA), "phi", "BSMWeights"))

            

            results.append(df_Nbb.Histo1D(("cos_1_Int", "", *bins_cos), "cos_1", "InterferenceWeights"))
            results.append(df_Nbb.Histo1D(("cos_2_Int", "", *bins_cos), "cos_2", "InterferenceWeights"))
            results.append(df_Nbb.Histo1D(("phi_Int", "", *bins_phiMELA), "phi", "InterferenceWeights"))

            
            results.append(df_bb.Histo1D(("D_0Minus_BSM", "", *bins_cos), "D_0Minus", "BSMWeights"))
            results.append(df_bb.Histo1D(("D_0Minus_Mix", "", *bins_cos), "D_0Minus", "MixtureWeights"))
            results.append(df_bb.Histo1D(("D_0Minus_NegMix", "", *bins_cos), "D_0Minus", "NegMixtureWeights")) 
            results.append(df_Nbb.Histo1D(("D_0Minus_BSM", "", *bins_cos), "D_0Minus", "BSMWeights"))
            results.append(df_Nbb.Histo1D(("D_0Minus_Mix", "", *bins_cos), "D_0Minus", "MixtureWeights"))
            results.append(df_Nbb.Histo1D(("D_0Minus_NegMix", "", *bins_cos), "D_0Minus", "NegMixtureWeights"))       

            results.append(df_bb.Histo1D(("cos_1_BSM_ScaledUp", "", *bins_cos), "cos_1", "ScaledUpBSMWeights"))
            results.append(df_Nbb.Histo1D(("cos_1_BSM_ScaledUp", "", *bins_cos), "cos_1", "ScaledUpBSMWeights"))   


            
            results.append(df_bb.Histo1D(("D_CP_BSM", "", *bins_cos), "D_CP", "BSMWeights"))
            results.append(df_bb.Histo1D(("D_CP_Mix", "", *bins_cos), "D_CP", "MixtureWeights"))
            results.append(df_bb.Histo1D(("D_CP_NegMix", "", *bins_cos), "D_CP", "NegMixtureWeights"))
            results.append(df_Nbb.Histo1D(("D_CP_BSM", "", *bins_cos), "D_CP", "BSMWeights"))
            results.append(df_Nbb.Histo1D(("D_CP_Mix", "", *bins_cos), "D_CP", "MixtureWeights"))
            results.append(df_Nbb.Histo1D(("D_CP_NegMix", "", *bins_cos), "D_CP", "NegMixtureWeights"))

            
            results.append(df_bb.Histo3D(("Angles_Template_BSM", "", *(bins_cos_Template + bins_cos_Template + bins_phi_Template)), "cos_1", "cos_2_corrected", "phi", "ScaledUpBSMWeights"))
            results.append(df_bb.Histo3D(("Angles_Template_Int", "", *(bins_cos_Template + bins_cos_Template + bins_phi_Template)), "cos_1", "cos_2_corrected", "phi", "InterferenceWeights"))
            results.append(df_Nbb.Histo3D(("Angles_Template_BSM", "", *(bins_cos_Template + bins_cos_Template + bins_phi_Template)), "cos_1", "cos_2_corrected", "phi", "ScaledUpBSMWeights"))
            results.append(df_Nbb.Histo3D(("Angles_Template_Int", "", *(bins_cos_Template + bins_cos_Template + bins_phi_Template)), "cos_1", "cos_2_corrected", "phi", "InterferenceWeights"))         

            results.append(df_bb.Histo3D(("bb_Angles_Template_BSM", "", *(bins_cos_Template + bins_cos_Template + bins_phi_Template)), "cos_1", "cos_2_corrected", "phi", "ScaledUpBSMWeights"))
            results.append(df_bb.Histo3D(("bb_Angles_Template_Int", "", *(bins_cos_Template + bins_cos_Template + bins_phi_Template)), "cos_1", "cos_2_corrected", "phi", "InterferenceWeights"))

            results.append(df_Nbb.Histo3D(("Nbb_Angles_Template_BSM", "", *(bins_cos_Template + bins_cos_Template + bins_phi_Template)), "cos_1", "cos_2_corrected", "phi", "ScaledUpBSMWeights"))
            results.append(df_Nbb.Histo3D(("Nbb_Angles_Template_Int", "", *(bins_cos_Template + bins_cos_Template + bins_phi_Template)), "cos_1", "cos_2_corrected", "phi", "InterferenceWeights"))

            results.append(df_bb.Histo3D(("ggH_SM_250", "", *(bins_D0Minus + bins_DCP + bins_TemplateMRec)), "D_0Minus", "D_CP", "recoil_mass", "nominal_weight"))
            results.append(df_bb.Histo1D(("D_0Minus", "", *bins_cos), "D_0Minus", "nominal_weight"))
            results.append(df_bb.Histo1D(("D_CP", "", *bins_cos), "D_CP", "nominal_weight")) 
            results.append(df_Nbb.Histo3D(("ggH_SM_250", "", *(bins_D0Minus + bins_DCP + bins_TemplateMRec)), "D_0Minus", "D_CP", "recoil_mass", "nominal_weight"))
            results.append(df_Nbb.Histo1D(("D_0Minus", "", *bins_cos), "D_0Minus", "nominal_weight"))
            results.append(df_Nbb.Histo1D(("D_CP", "", *bins_cos), "D_CP", "nominal_weight")) 

            
           # results.append(df_bb.Histo3D(("ggH_g4ZZ_250", "", *(bins_D0Minus + bins_DCP + bins_TemplateMRec)), "D_0Minus", "D_CP", "recoil_mass", "ScaledUpBSMWeights"))
           # results.append(df_bb.Histo3D(("ggH_interff_g11g41_250", "", *(bins_D0Minus + bins_DCP + bins_TemplateMRec)), "D_0Minus", "D_CP", "recoil_mass", "InterferenceWeights"))
           # results.append(df_Nbb.Histo3D(("ggH_g4ZZ_250", "", *(bins_D0Minus + bins_DCP + bins_TemplateMRec)), "D_0Minus", "D_CP", "recoil_mass", "ScaledUpBSMWeights"))
           # results.append(df_Nbb.Histo3D(("ggH_interff_g11g41_250", "", *(bins_D0Minus + bins_DCP + bins_TemplateMRec)), "D_0Minus", "D_CP", "recoil_mass", "InterferenceWeights"))



    results.append(df_bb.Histo1D(("Z_mass_bb", "", *bins_m_Z), "Z_mass"))
    results.append(df_bb.Histo1D(("Z_Mass_MC_bb", "", *bins_m_Z), "Z_Mass_MC"))
    results.append(df_bb.Histo1D(("Z_p_bb", "", *bins_p_ll), "Z_p"))

    results.append(df_bb.Histo1D(("recoil_mass_bb", "", *bins_m_Z), "recoil_mass"))
    results.append(df_bb.Histo1D(("recoil_mass_corrected_bb", "", *bins_m_Z), "recoil_mass_corrected"))


    results.append(df_Nbb.Histo1D(("Z_mass_Nbb", "", *bins_m_Z), "Z_mass"))
    results.append(df_Nbb.Histo1D(("Z_p_Nbb", "", *bins_p_ll), "Z_p"))
    results.append(df_Nbb.Histo1D(("recoil_mass_Nbb", "", *bins_m_Z), "recoil_mass"))
    results.append(df_Nbb.Histo1D(("recoil_mass_corrected_Nbb", "", *bins_m_Z), "recoil_mass_corrected"))


    results.append(df_Nbb.Histo1D(("Z_mass", "", *bins_m_Z), "Z_mass"))
    results.append(df_Nbb.Histo1D(("Z_p", "", *bins_p_ll), "Z_p"))
    results.append(df_Nbb.Histo1D(("recoil_mass", "", *bins_m_Z), "recoil_mass"))
    results.append(df_Nbb.Histo1D(("recoil_mass_corrected", "", *bins_m_Z), "recoil_mass_corrected"))

    results.append(df_bb.Histo1D(("Z_mass", "", *bins_m_Z), "Z_mass"))
    results.append(df_bb.Histo1D(("Z_p", "", *bins_p_ll), "Z_p"))
    results.append(df_bb.Histo1D(("recoil_mass", "", *bins_m_Z), "recoil_mass"))
    results.append(df_bb.Histo1D(("recoil_mass_corrected", "", *bins_m_Z), "recoil_mass_corrected"))

    #results.append(df_bb.Histo1D(("jets_pt", "", *bins_p_ll), "jets_pt"))
    #results.append(df_bb.Histo1D(("Jets_No", "", *bins_count), "Jets_No"))

    # results.append(df_bb.Histo1D(("full_decays", "", *bins_count), "full_decays"))
    # results.append(df_bb.Histo1D(("full_decays_1", "", *bins_count), "full_decays_1"))
    # results.append(df_bb.Histo1D(("full_decays_2", "", *bins_count), "full_decays_2"))
    # results.append(df_bb.Histo1D(("full_decays_3", "", *bins_count), "full_decays_3"))

    # results.append(df_bb.Histo1D(("zll_m", "", *bins_p_ll), "zll_m"))
    # results.append(df_bb.Histo1D(("zll_m_recoil_m", "", *bins_p_ll), "zll_recoil_m"))

  
    results.append(df_bb.Histo1D(("jets_truth", "", *bins_pdgid), "jetsTruthPDG"))
    results.append(df_bb.Histo1D(("Best_Jets_TruthPDG", "", *bins_pdgid), "BestJetsTruthPDG"))
    results.append(df_bb.Histo1D(("Best_Jets_TruthZ", "", *bins_binary), "BestJetsTruthZ"))
    #results.append(df_bb.Histo1D(("HiggsIdx", "", *bins_count), "HiggsIdx[0]"))

    df_bb = df_bb.Filter("BestJetsTruthZ[0] == 1.0")
    df_Nbb = df_Nbb.Filter("BestJetsTruthZ[0] == 1.0")

    results.append(df_bb.Histo1D(("Z_massTrueJets", "", *bins_m_Z), "Z_mass"))
    results.append(df_bb.Histo1D(("Z_Mass_MCTrueJets", "", *bins_m_Z), "Z_Mass_MC"))
    results.append(df_bb.Histo1D(("Z_ptTrueJets", "", *bins_p_ll), "Z_pt"))
    results.append(df_bb.Histo1D(("Z_pt_MCTrueJets", "", *bins_p_ll), "Z_pt_MC"))
    results.append(df_bb.Histo1D(("Z_pTrueJets", "", *bins_p_ll), "Z_p"))
    results.append(df_bb.Histo1D(("CScoreSumTruth", "", *bins_jet_scoreSum), "CScoreSum"))
    results.append(df_bb.Histo1D(("recoil_massTrueJets", "", *bins_m_Z), "recoil_mass"))
    results.append(df_bb.Histo1D(("recoil_mass_correctedTrueJets", "", *bins_m_Z), "recoil_mass_corrected"))
    results.append(df_bb.Histo1D(("cos_1TrueJets", "", *bins_cos), "cos_1"))
    results.append(df_bb.Histo1D(("cos_2TrueJets", "", *bins_cos), "cos_2"))
    results.append(df_bb.Histo1D(("cos_2_correctedTrueJets", "", *bins_cos), "cos_2_corrected"))
    results.append(df_bb.Histo1D(("phiTrueJets", "", *bins_phiMELA), "phi"))

    results.append(df_Nbb.Histo1D(("Z_massTrueJets", "", *bins_m_Z), "Z_mass"))
    results.append(df_Nbb.Histo1D(("Z_Mass_MCTrueJets", "", *bins_m_Z), "Z_Mass_MC"))
    results.append(df_Nbb.Histo1D(("Z_ptTrueJets", "", *bins_p_ll), "Z_pt"))
    results.append(df_Nbb.Histo1D(("Z_pt_MCTrueJets", "", *bins_p_ll), "Z_pt_MC"))
    results.append(df_Nbb.Histo1D(("Z_pTrueJets", "", *bins_p_ll), "Z_p"))
    results.append(df_Nbb.Histo1D(("CScoreSumTruth", "", *bins_jet_scoreSum), "CScoreSum"))
    results.append(df_Nbb.Histo1D(("recoil_massTrueJets", "", *bins_m_Z), "recoil_mass"))
    results.append(df_Nbb.Histo1D(("recoil_mass_correctedTrueJets", "", *bins_m_Z), "recoil_mass_corrected"))
    results.append(df_Nbb.Histo1D(("cos_1TrueJets", "", *bins_cos), "cos_1"))
    results.append(df_Nbb.Histo1D(("cos_2TrueJets", "", *bins_cos), "cos_2"))
    results.append(df_Nbb.Histo1D(("cos_2_correctedTrueJets", "", *bins_cos), "cos_2_corrected"))
    results.append(df_Nbb.Histo1D(("phiTrueJets", "", *bins_phiMELA), "phi"))


    



    # results.append(df_bb.Histo1D(("full_decays_size", "", *bins_pdgid), "full_decays_size"))

    weightsum = df_bb.Sum("nominal_weight")
    threading.Thread(target=print_process_id).start()
    return results, weightsum 
threading.Thread(target=print_process_id).start()
    
