#include "custom_sf.h"

MyCorrections::MyCorrections(std::string filename, std::string correction_name) {
  auto csetEl = correction::CorrectionSet::from_file(filename);
  SF_ = csetEl->at(correction_name);
}

double MyCorrections::eval_deepjet(
    std::string syst, std::string wp, int flavor, double eta, double pt) {
  return SF_->evaluate({syst, wp, flavor, fabs(eta), pt});
};
