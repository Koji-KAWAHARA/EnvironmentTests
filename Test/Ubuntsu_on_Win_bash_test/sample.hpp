#ifndef DEBUG_MODE_HPP
#define DEBUG_MODE_HPP
//sample hpp file, copy of DEBUG_MODE.hpp from GdFeO3 project


//debug directive
//#define NEWTON
//#define DEBUG_CG
//#define DEBUG_INICON
//#define ENERGY_BASED_GRADIENT
#define ROUGH_CG_EVALUATION     // Use just Eular method instead of RK45 method in CG approach

//dt_update method. pick 1.
//#define FIXED_DT              // supress adoptive-dt in function CG1step. This will fix learning rate of CGmethod to the value listed in model_parm.dat.
//#define DT_UPDATE_ADD_SUB
#define DT_UPDATE_MUL_DIV       // this was the fastest of 4 methods(see:RUN20221026)
//#define DT_UPDATE_ADD_LOG
//
#define FORCE_ENERGY_DECREASE //force energy decrease when searching for dt

//openmp
#define USE_OPENMP

//1dim anneal flag for Iniconfig.hpp
//#define ONEDIM_ANNEAL


#endif //DEBUG_MODE_HPP