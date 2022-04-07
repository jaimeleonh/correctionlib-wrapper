#include "correction.h"
#include <math.h> 

class MyCorrections {
  public:
    MyCorrections(std::string filename, std::string correction_name);
    double eval(std::string str1, std::string str2, int int1, double double1, double double2);
    double eval(double double1, int int1, std::string str1, std::string str2);
    double eval(
        double double1, int int1, int int2, std::string str1, std::string str2, std::string str3);
    double eval(
        double double1, double double2, int int1, int int2, std::string str1, std::string str2);
    double eval(
        double double1, int int1, std::string str1,
        std::string str2, std::string str3, std::string str4);

  private:
    correction::Correction::Ref SF_;
};
