import ROOT



# global parameters
intLumi         = 1. # already scaled in histmaker
intLumiLabel    = "L = 7.2 ab^{-1}"
ana_tex         = f'e^{{+}}e^{{-}} #rightarrow ZH #rightarrow + X'
delphesVersion  = '3.4.2'
energy          = 240.0
collider        = 'FCC-ee'
#inputDir        = f'output_{flavor}/'
inputDir        = 'jetTests/'
formats         = ['pdf', 'png']
#outdir          = f'plots_{flavor}/'
outdir          = 'jetPlots/'
plotStatUnc     = False

colors = {}
colors['ZH_0+']    = ROOT.kRed
colors['WW']    = ROOT.TColor.GetColor(248, 206, 104)
#colors['ZZ']    = ROOT.TColor.GetColor(222, 90, 106)


procs = {}
procs['signal'] =   {'ZH_0+':[f'wzp6_ee_bbH_Hmumu_ecm240']}
procs['backgrounds'] = {}
procs['backgrounds']['WW'] = ['p8_ee_WW_ecm240']
#procs['backgrounds']['ZZ'] = ['p8_ee_ZZ_ecm240']
#procs['backgrounds']['Zg'] = ['wzp6_ee_tautau_ecm240', 'wzp6_ee_mumu_ecm240' if flavor=="mumu" else 'wzp6_ee_ee_Mee_30_150_ecm240']
#procs['backgrounds']['rare'] = [f'wzp6_egamma_eZ_Z{flavor}_ecm240', f'wzp6_gammae_eZ_Z{flavor}_ecm240', f'wzp6_gaga_{flavor}_60_ecm240', 'wzp6_gaga_tautau_60_ecm240', 'wzp6_ee_nuenueZ_ecm240']


legend = {}
legend['ZH_0+']    = "ZH_0+"
legend['WW']    = "W^{+}W^{#minus}"
#legend['ZZ']    = "ZZ"
# legend['Zg']    = "Z/#gamma^{*}"
# legend['rare']  = "Rare"


hists = {}


hists["Z_mass"] = {
    "output":   "Z_mass",
    "logy":     False,
    "stack":    False,
    "rebin":    1,
    "xmin":     86,
    "xmax":     120,
    "xtitle":   f"m(Jets) (GeV)",
    "ytitle":   "Events ",
}





