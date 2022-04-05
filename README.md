# correctionlib-wrapper

Wrapper class to use correctionlib in RDataFrame with ROOT from CMSSW (correctionlib [issue](https://github.com/cms-nanoAOD/correctionlib/issues/121#issuecomment-1033040803)).

## Compilation
This class can't be compiled (easily, probably it can) in CMSSW_11*, so we upload the shared library to the repo.
In case it has to be modified:

1. CMSSW setup installation 
```
cmsrel CMSSW_12_3_0_pre1
cd CMSSW_12_3_0_pre1/src
cmsenv
git clone https://github.com/jaimeleonh/correctionlib-wrapper.git
cd correctionlib-wrapper
```
2. Apply modifications.
3. Compile afterwards:
```
g++ $(correction config --cflags --ldflags) custom_sf.cc -shared -fPIC -o custom_sf.so
```
4. Reupload


## Instalation (in the CMT framework)

### Installation
Inside a CMSSW setup:
```
cmsenv
git clone --recursive https://github.com/cms-nanoAOD/correctionlib.git
cd correctionlib
make PYTHON=python
make install
mv correctionlib $CMT_BASE/
cd ..
rm -rf correctionlib
```
### Actual wrapper 

```
git clone https://github.com/jaimeleonh/correctionlib-wrapper.git
cd correctionlib-wrapper
echo \#include \"$CMT_BASE/correctionlib/include/correction.h\" > custom_custom_sf.h
tail -n +2 custom_sf.h >> custom_custom_sf.h
mv custom_custom_sf.h custom_sf.h
```
