import ROOT

import sys
if sys.version_info[0] >= 3:
    import correctionlib
    correctionlib.register_pyroot_binding()

filename = "/afs/cern.ch/work/j/jleonhol/public/btagging.json"
correction_name = "deepJet_comb"

ROOT.gInterpreter.Load("libCorrectionsWrapper.so")

ROOT.gInterpreter.Declare('#include "../interface/custom_sf.h"')
ROOT.gInterpreter.ProcessLine('auto corr = MyCorrections("%s", "%s");' % (filename, correction_name))

df = ROOT.RDataFrame("Events", "/afs/cern.ch/work/j/jleonhol/public/nanoaod_example.root")
df = df.Filter("nJet >= 1").Filter("abs(Jet_eta.at(0)) < 2.4").Define(
    "number", 'corr.eval("central", "M", 5, abs(Jet_eta.at(0)), Jet_pt.at(0))')


histo = df.Histo1D("number")
c = ROOT.TCanvas()
histo.Draw()
c.SaveAs("test_plot.pdf")
