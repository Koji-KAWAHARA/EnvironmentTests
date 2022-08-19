//latest dpcpp code does not have M_PI defines
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <mkl.h>    //WARNING!! - USE "LP64" interface of MKL. (NOT "ILP64")
#define EIGEN_USE_MKL_ALL
#include <Eigen/Core>       //core
#include <Eigen/Dense>      //for dense matrix
#include <Eigen/SparseCore> //for sparse matrix


#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <numbers>


int main(int argc, char* argv[]){

    if(argc>1){
        std::string arg1(argv[1]);
        std::cout<<argc<<" "<<arg1<<" "<<(std::string)argv[2]<<std::endl;
    }
    else{
        std::cout<<"no arg. @ commandline"<<std::endl;
    }

    Eigen::Matrix2d A;
    A << 1,2,3,4;
    std::cout << A <<std::endl;
    std::cout << "cmath PI = " << M_PI << std::endl;
    std::cout<<"sucsess"<<std::endl; 
    return 0;
}