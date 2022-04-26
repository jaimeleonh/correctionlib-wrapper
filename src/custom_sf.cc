#include "Corrections/Wrapper/interface/custom_sf.h"

MyCorrections::MyCorrections(std::string filename, std::string correction_name) {
  auto csetEl = correction::CorrectionSet::from_file(filename);
  SF_ = csetEl->at(correction_name);
}

double MyCorrections::eval(const std::vector<correction::Variable::Type>& values) {
  return SF_->evaluate(values);
}
