#ifndef Corrections_Wrapper_custom_sf_
#define Corrections_Wrapper_custom_sf_

#include "correction.h"
#include <math.h> 

class MyCorrections {
  public:
    MyCorrections(std::string filename, std::string correction_name);  
    double eval(const std::vector<correction::Variable::Type>& values);

  private:
    correction::Correction::Ref SF_;
};

#endif