import ROOT



# global parameters
intLumi         = 1. # already scaled in histmaker
intLumiLabel    = "L = 7.2 ab^{-1}"
ana_tex         = f'e^{{+}}e^{{-}} #rightarrow ZZ'
delphesVersion  = '3.4.2'
energy          = 240.0
collider        = 'FCC-ee'
#inputDir        = f'output_{flavor}/'
inputDir        = '/eos/user/n/nipinto/FCCAnalyses_MELA/analysis/FCCAnalysisOut/ZZComparison'
formats         = ['pdf', 'png']
#outdir          = f'plots_{flavor}/'
outdir          = '/eos/user/n/nipinto/FCCAnalyses_MELA/analysis/FCCAnalysisOut/ZZComparison'
plotStatUnc     = False

colors = {}
colors['bb_ZZ']    = ROOT.kBlue
colors['mumu_ZZ']    = ROOT.TColor.GetColor(222, 90, 106)
# colors['Dummy'] = ROOT.kRed


procs = {}
procs['signal'] =   {'bb_ZZ':['bb_p8_ee_ZZ_ecm240_WXSec']}
procs['backgrounds'] = {'mumu_ZZ':['mumu_p8_ee_ZZ_ecm240_WXSec']}
#procs['backgrounds']['WW'] = ['p8_ee_WW_ecm240']
#procs['backgrounds']['ZZ'] = ['p8_ee_ZZ_ecm240']
#procs['backgrounds']['Zg'] = ['wzp6_ee_tautau_ecm240', 'wzp6_ee_mumu_ecm240' if flavor=="mumu" else 'wzp6_ee_ee_Mee_30_150_ecm240']
#procs['backgrounds']['rare'] = [f'wzp6_egamma_eZ_Z{flavor}_ecm240', f'wzp6_gammae_eZ_Z{flavor}_ecm240', f'wzp6_gaga_{flavor}_60_ecm240', 'wzp6_gaga_tautau_60_ecm240', 'wzp6_ee_nuenueZ_ecm240']


legend = {}
legend['bb_ZZ']    = "bb_ZZ"
legend['mumu_ZZ']  = "mumu_ZZ"
#legend['WW']    = "W^{+}W^{#minus}"
#legend['ZZ']    = "ZZ"
#legend['Dummy'] = ""
# legend['Zg']    = "Z/#gamma^{*}"
# legend['rare']  = "Rare"


hists = {}


hists["Z_mass"] = {
    "output":   "Z_mass",
    "logy":     False,
    "stack":    False,
    "rebin":    20,
    "xmin":     60,
    "xmax":     100,
    "xtitle":   f"m(Dijet) (GeV)",
    "ytitle":   "Events ",
    "scaleSig": 1/100
}

hists["Z_p"] = {
    "output":   "Z_p",
    "logy":     False,
    "stack":    False,
    "rebin":    2,
    "xmin":     20,
    "xmax":     60,
    "xtitle":   f"p(Dijet) (GeV)",
    "ytitle":   "Events ",
    "scaleSig": 1/100
}


# hists["Z_mass_nmone"] = {
#     "output":   "Z_mass_nmone",
#     "logy":     False,
#     "stack":    False,
# #    "rebin":    20,
#     "xmin":     5,
#     "xmax":     120,
#     "xtitle":   f"m(Dijet) (GeV)",
#     "ytitle":   "Events ",
#     "scaleSig": 1/100
# }

hists["Z_p_nmone"] = {
    "output":   "Z_p_nmone",
    "logy":     False,
    "stack":    False,
    "rebin":    2,
    "xmin":     0,
    "xmax":     100,
    "xtitle":   f"p(Dijet) (GeV)",
    "ytitle":   "Events ",
    "scaleSig": 3/100
}


# hists["W_chi"] = {
#     "output":   "W_chi",
#     "logy":     False,
#     "stack":    False,
#     "rebin":    20,
#     "xmin":     0,
#     "xmax":     100,
#     "xtitle":   f"W_chi",
#     "ytitle":   "Events ",
#     "scaleSig": 100
# }

# hists["Z_chi"] = {
#     "output":   "Z_chi",
#     "logy":     False,
#     "stack":    False,
#     "rebin":    20,
#     "xmin":     0,
#     "xmax":     100,
#     "xtitle":   f"Z_chi",
#     "ytitle":   "Events ",
#     "scaleSig": 100
# }

# hists["chi"] = {
#     "output":   "chi",
#     "logy":     False,
#     "stack":    False,
#     "rebin":    20,
#     "xmin":     0,
#     "xmax":     100,
#     "xtitle":   f"chi",
#     "ytitle":   "Events ",
#     "scaleSig": 100
# }

hists["recoil_mass"] = {
    "output":   "recoil_mass",
    "logy":     False,
    "stack":    False,
     "rebin":    200,
    "xmin":     80,
    "xmax":     160,
    "xtitle":   f"m(Rec) (GeV)",
    "ytitle":   "Events ",
    "scaleSig": 1/100
}


hists["recoil_mass_nmone"] = {
    "output":   "recoil_mass_nmone",
    "logy":     False,
    "stack":    False,
    # "rebin":    20,
    "xmin":     80,
    "xmax":     160,
    "xtitle":   f"m(Rec) (GeV)",
    "ytitle":   "Events ",
    "scaleSig": 1/100
}

# hists["recoil_mass_corrected"] = {
#     "output":   "recoil_mass_corrected",
#     "logy":     False,
#     "stack":    False,
#     "rebin":    20,
#     "xmin":     80,
#     "xmax":     160,
#     "xtitle":   f"m(Rec) (GeV)",
#     "ytitle":   "Events ",
#     "scaleSig": 100
# }

# hists["cos_1"] = {
#     "output":   "cos_1",
#     "logy":     False,
#     "stack":    False,
#    # "rebin":    20,
#     "xmin":     -1,
#     "xmax":     1,
#     "xtitle":   f"cos_1",
#     "ytitle":   "Events ",
#     "scaleSig": 100
# }

# hists["cos_2_corrected"] = {
#     "output":   "cos_2_corrected",
#     "logy":     False,
#     "stack":    False,
#     #"rebin":    20,
#     "xmin":     -1,
#     "xmax":     1,
#     "xtitle":   f"cos_2_corrected",
#     "ytitle":   "Events ",
#     "scaleSig": 100
# }

# hists["phi"] = {
#     "output":   "phi",
#     "logy":     False,
#     "stack":    False,
#    # "rebin":    20,
#     "xmin":     -3.1415,
#     "xmax":     3.1415,
#     "xtitle":   f"phi",
#     "ytitle":   "Events ",
#     "scaleSig": 100
# }


hists["cutFlow"] = {
    "output":   "cutFlow",
    "logy":     True,
    "stack":    False,
    "xmin":     0,
    "xmax":     8,
    "ymin":     1e3,
    "ymax":     1e11,
 #   "xtitle":   ["All events", f"e <= 2", f"p(e) < 20 GeV", f"mu <= 2", f"p(mu) < 20 GeV", "vis_M, vis_E > 150 GeV, 0.15 < vis_theta < 3.0", "110 < mRec < 145", "60 < m(Z) < 100", "20 < p(Z) < 60", "W_chi & Z_chi > 10"],
    "ytitle":   "Events ",
    "scaleSig": 1
}






