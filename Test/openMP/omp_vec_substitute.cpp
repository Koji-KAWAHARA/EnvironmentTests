//test program for vector substitution using openmp
/*
Matrix M = Matrix_of_size_(N,M)
Vector V = Vector_of_size_N*M   : flattend version of M
V(M*i+j) = M(i,j)
*/

#define EIGEN_USE_MKL_ALL
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <iostream>
#include <mkl.h>    //WARNING!! - USE "LP64" interface of MKL. (NOT "ILP64")
#include <Eigen/Core>       //core
#include <Eigen/Dense>      //for dense matrix
#include <Eigen/SparseCore> //for sparse matrix

int N=4;
int M=4;

int main(void){
    //sequential version

}