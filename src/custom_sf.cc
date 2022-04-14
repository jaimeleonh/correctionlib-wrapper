#include "Corrections/Wrapper/interface/custom_sf.h"

MyCorrections::MyCorrections(std::string filename, std::string correction_name) {
  auto csetEl = correction::CorrectionSet::from_file(filename);
  SF_ = csetEl->at(correction_name);
}

double MyCorrections::eval(
    std::string str1, std::string str2, int int1, double double1, double double2) {
  return SF_->evaluate({str1, str2, int1, double1, double2});  
}

double MyCorrections::eval(
    double double1, int int1, std::string str1, std::string str2) {
  return SF_->evaluate({double1, int1, str1, str2});  
}

double MyCorrections::eval(
    double double1, double double2, std::string str1, std::string str2) {
  return SF_->evaluate({double1, double2, str1, str2});  
}

double MyCorrections::eval(
    double double1, int int1, int int2, std::string str1, std::string str2, std::string str3) {
  return SF_->evaluate({double1, int1, int2, str1, str2, str3});  
}

double MyCorrections::eval(
    double double1, double double2, int int1, int int2, std::string str1, std::string str2) {
  return SF_->evaluate({double1, double2, int1, int2, str1, str2});
}

double MyCorrections::eval(
    double double1, int int1, std::string str1,
    std::string str2, std::string str3, std::string str4) {
  return SF_->evaluate({double1, int1, str1, str2, str3, str4});
}

