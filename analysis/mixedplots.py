import ROOT



# global parameters
intLumi         = 1. # already scaled in histmaker
intLumiLabel    = "L = 7.2 ab^{-1}"
ana_tex         = f'e^{{+}}e^{{-}} #rightarrow ZH'
delphesVersion  = '3.4.2'
energy          = 240.0
collider        = 'FCC-ee'
#inputDir        = f'output_{flavor}/'
inputDir        = '/eos/user/n/nipinto/FCCAnalyses_MELA/analysis/bscorecompare/'
formats         = ['pdf', 'png']
#outdir          = f'plots_{flavor}/'
outdir          = 'jetPlots/ECFA/'
plotStatUnc     = False

colors = {}
colors['ZH_bb']    = ROOT.kRed
# colors['WW']    = ROOT.TColor.GetColor(248, 206, 104)
# colors['ZZ']    = ROOT.TColor.GetColor(222, 90, 106)
# colors['Zqq'] = ROOT.TColor.GetColor(100, 192, 232)
colors['rare']  = ROOT.TColor.GetColor(155, 152, 204)
# colors['rare'] = ROOT.kPurple
# colors['Dummy'] = ROOT.kRed


procs = {}
procs['signal'] =   {'ZH_bb':[f'bbsig']}
procs['backgrounds'] = {}
# procs['backgrounds']['qq'] = ['qqSig']
# procs['backgrounds']['ZZ'] = ['p8_ee_ZZ_ecm240']
# procs['backgrounds']['Zqq'] = ['p8_ee_Zqq_ecm240']
#procs['backgrounds']['Zg'] = ['wzp6_ee_tautau_ecm240', 'wzp6_ee_mumu_ecm240' if flavor=="mumu" else 'wzp6_ee_ee_Mee_30_150_ecm240']
procs['backgrounds']['rare'] = ['hbb']


legend = {}
legend['ZH_bb']    = "Z #rightarrow bb"
# legend['qq']    = "qq"
# legend['ZZ']    = "ZZ"
# #legend['Dummy'] = ""
# legend['Zqq']    = r"Z* #rightarrow qq"
legend['rare']  = "Z #rightarrow qq, H #rightarrow bb"


hists = {}


# hists["Z_mass_Nbb"] = {
#     "output":   "Z_mass",
#     "logy":     False,
#     "stack":    True,
#     "rebin":    20,
#     "xmin":     80,
#     "xmax":     100,
#     "xtitle":   f"m(Dijet) (GeV)",
#     "ytitle":   "Events ",
#     "scaleSig": 1
# }

# hists["Z_mass_nmone_NHCB"] = {
#     "output":   "Z_mass_nmone",
#     "logy":     False,
#     "stack":    True,
#     "rebin":    20,
#     "xmin":     0,
#     "xmax":     120,
#     "xtitle":   f"m(Dijet) (GeV)",
#     "ytitle":   "Events ",
#     "scaleSig": 1
# }

# hists["vis_E"] = {
#     "output":   "vis_E",
#     "logy":     False,
#     "stack":    False,
#     "rebin":    2,
#     "xmin":     0,
#     "xmax":     240,
#     "xtitle":   f"Visible Energy (GeV)",
#     "ytitle":   "Events ",
#     "scaleSig": 1
# }

# hists["Z_p_nmone_NHCB"] = {
#     "output":   "Z_p_nmone",
#     "logy":     False,
#     "stack":    True,
#     "rebin":    2,
#     "xmin":     0,
#     "xmax":     100,
#     "xtitle":   f"p(Dijet) (GeV)",
#     "ytitle":   "Events ",
#     "scaleSig": 1
# }

# hists["d_12_nmone"] = {
#     "output":   "d_12_nmone",
#     "logy":     False,
#     "stack":    False,
#     "rebin":    2000,
#     "xmin":     0,
#     "xmax":     100000,
#     "xtitle":   f"",
#     "ytitle":   "Events ",
#     "scaleSig": 100
# }

# hists["d_23_nmone"] = {
#     "output":   "d_23_nmone",
#     "logy":     False,
#     "stack":    False,
#     "rebin":    200,
#     "xmin":     0,
#     "xmax":     30000,
#     "xtitle":   f"",
#     "ytitle":   "Events ",
#     "scaleSig": 100
# }

# hists["d_34_nmone"] = {
#     "output":   "d_34_nmone",
#     "logy":     False,
#     "stack":    False,
#     "rebin":    20,
#     "xmin":     0,
#     "xmax":     20000,
#     "xtitle":   f"",
#     "ytitle":   "Events ",
#     "scaleSig": 100
# }

# hists["d_56_nmone"] = {
#     "output":   "d_56_nmone",
#     "logy":     False,
#     "stack":    False,
#     "rebin":    20,
#     "xmin":     0,
#     "xmax":     1000,
#     "xtitle":   f"",
#     "ytitle":   "Events ",
#     "scaleSig": 100
# }

# hists["d_78_nmone"] = {
#     "output":   "d_78_nmone",
#     "logy":     False,
#     "stack":    False,
#     "rebin":    20,
#     "xmin":     0,
#     "xmax":     200,
#     "xtitle":   f"",
#     "ytitle":   "Events ",
#     "scaleSig": 1
# }

# hists["d_89_nmone"] = {
#     "output":   "d_89_nmone",
#     "logy":     False,
#     "stack":    False,
#     "rebin":    20,
#     "xmin":     0,
#     "xmax":     20,
#     "xtitle":   f"",
#     "ytitle":   "Events ",
#     "scaleSig": 100
# }








# hists["W_chi"] = {
#     "output":   "W_chi",
#     "logy":     False,
#     "stack":    False,
#     "rebin":    20,
#     "xmin":     0,
#     "xmax":     100,
#     "xtitle":   f"W_chi",
#     "ytitle":   "Events ",
#     "scaleSig": 1
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
#     "scaleSig": 1
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
#     "scaleSig": 1
# }

# hists["recoil_mass_Nbb"] = {
#     "output":   "recoil_mass",
#     "logy":     False,
#     "stack":    True,
#     "rebin":    20,
#     "xmin":     110,
#     "xmax":     150,
#     "xtitle":   f"m(Rec) (GeV)",
#     "ytitle":   "Events ",
#     "scaleSig": 1
# }

# hists["recoil_mass_nmone_NHCB"] = {
#     "output":   "recoil_mass_nmone",
#     "logy":     False,
#     "stack":    True,
#     "rebin":    20,
#     "xmin":     0,
#     "xmax":     160,
#     "xtitle":   f"m(Rec) (GeV)",
#     "ytitle":   "Events ",
#     "scaleSig": 1
# }

# hists["recoil_mass_corrected_Nbb"] = {
#     "output":   "recoil_mass_corrected",
#     "logy":     False,
#     "stack":    True,
#     "rebin":    20,
#     "xmin":     110,
#     "xmax":     140,
#     "xtitle":   f"m(Rec) (GeV)",
#     "ytitle":   "Events ",
#     "scaleSig": 1
# }

# hists["cos_1_Nbb"] = {
#     "output":   "cos_1",
#     "logy":     False,
#     "stack":    False,
#    # "rebin":    20,
#     "xmin":     -1,
#     "xmax":     1,
#     "xtitle":   f"cos_1",
#     "ytitle":   "Events ",
#     "scaleSig": 10
# }

# hists["cos_2_corrected_Nbb"] = {
#     "output":   "cos_2_corrected",
#     "logy":     False,
#     "stack":    False,
#     #"rebin":    20,
#     "xmin":     -1,
#     "xmax":     1,
#     "xtitle":   f"cos_2",
#     "ytitle":   "Events ",
#     "scaleSig": 10
# }

# hists["phi_Nbb"] = {
#     "output":   "phi",
#     "logy":     False,
#     "stack":    False,
#    # "rebin":    20,
#     "xmin":     -3.1415,
#     "xmax":     3.1415,
#     "xtitle":   f"phi",
#     "ytitle":   "Events ",
#     "scaleSig": 10
# }

hists["BScoreSum_nmone"] = {
    "output":   "BScoreSum_nmone",
    "logy":     False,
    "stack":    False,
    # "rebin":    ,
    "xmin":     0,
    "xmax":     2,
    "xtitle":   f"BScoreSum(Dijet)",
    "ytitle":   "Events ",
    "scaleSig": 1
}

# hists["Nbb_cutFlow"] = {
#     "output":   "cutFlow",
#     "logy":     True,
#     "stack":    False,
#     "xmin":     0,
#     "xmax":     7,
#     "ymin":     1e3,
#     "ymax":     1e11,
#     #"xtitle":   ["All events", f"e <= 2", f"p(e) < 20 GeV", f"mu <= 2", f"p(mu) < 20 GeV", "vis_M, vis_E > 150 GeV, 0.15 < vis_theta < 3.0", "110 < mRec < 145", "60 < m(Z) < 100", "20 < p(Z) < 60", "W_chi & Z_chi > 10"],
#     "ytitle":   "Events ",
#     "scaleSig": 1
# }






