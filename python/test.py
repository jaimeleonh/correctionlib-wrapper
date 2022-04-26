import ROOT

filename = "/afs/cern.ch/work/j/jleonhol/public/btagging.json"
correction_name = "deepJet_comb"

import sys
if sys.version_info[0] >= 3:
    import correctionlib
    correctionlib.register_pyroot_binding()

ROOT.gInterpreter.Load("libCorrectionsWrapper.so")

ROOT.gInterpreter.Declare('#include "../interface/custom_sf.h"')
ROOT.gInterpreter.ProcessLine('auto corr = MyCorrections("%s", "%s");' % (filename, correction_name))

eta = 1.2
pt = 240.

ROOT.gInterpreter.ProcessLine('corr.eval({"central", "M", 5, abs(%s), %s})'% (eta, pt))
