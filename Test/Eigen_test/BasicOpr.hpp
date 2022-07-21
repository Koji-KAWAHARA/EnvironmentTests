//latest dpcpp code does not have M_PI defines


#ifndef BASIC_OPR_HPP
#define BASIC_OPR_HPP

#define EIGEN_USE_MKL_ALL
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <random>

#include <mkl.h>    //WARNING!! - USE "LP64" interface of MKL. (NOT "ILP64")
#include <Eigen/Core>       //core
#include <Eigen/Dense>      //for dense matrix
#include <Eigen/SparseCore> //for sparse matrix

#define INT MKL_INT
#define MAXBUFSIZE  ((int)1e6)  //for function ReadMatrix


//RK45 parameter
extern Eigen::MatrixXd rk;
//rk(0,:) is for evaluating residue (5th_order_prediction - 4th_order_prediction).
//rk(1,:) is for evaluating 4th_order_prediction itself.
//else is for determination of prediction for each step.




//for debug
void flag(std::string message);

// a mod b, but answer is always positive (ex posmod(-5,3) = 1, not -2)
INT posmod(INT a, INT b);

//return random double in range (min,max)
double rand_double(const double min,const double max);

//readmatrix from file
Eigen::MatrixXd ReadMatrix(const std::string filename);

Eigen::MatrixXd Printeye(int n);

//convert string to integer vector. (delimiter of the string should be " ")
Eigen::Vector<INT,Eigen::Dynamic> string_to_ivector(std::string str);

//find maximum element in a matrix
double find_max_element(const Eigen::MatrixXd mat);
int find_max_element(const Eigen::MatrixXi mat);

#endif /* BASIC_OPR_HPP */
