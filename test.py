import ROOT

filename = "/afs/cern.ch/work/j/jleonhol/public/btagging.json"
correction_name = "deepJet_comb"

ROOT.gInterpreter.Load("custom_sf.so")

ROOT.gInterpreter.Declare('#include "custom_sf.h"')
ROOT.gInterpreter.ProcessLine('auto corr = MyCorrections("%s", "%s");' % (filename, correction_name))
ROOT.gInterpreter.ProcessLine('corr.eval_deepjet("central", "M", 5, 1.2, 240.)')
