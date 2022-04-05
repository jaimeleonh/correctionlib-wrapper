// #include "correction.h"
#include <math.h> 
#include "/afs/cern.ch/work/j/jleonhol/private/nanoaod_test/correctionlib/include/correction.h"

class MyCorrections {
  public:
    MyCorrections(std::string filename, std::string correction_name);
    double eval_deepjet(std::string syst, std::string wp, int flavor, double eta, double pt);

  private:
    correction::Correction::Ref SF_;
};
