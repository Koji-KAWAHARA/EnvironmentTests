//test program for vector substitution using openmp
/*
Matrix Mat = Matrix_of_size_(N,M)
Vector Vec = Vector_of_size_N*M   : flattend version of M
Vec(M*i+j) = Mat(i,j)
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

#include <omp.h>


int main(void){
    omp_set_num_threads(2);
    int N=4;
    int M=4;
    Eigen::MatrixXd Mat = Eigen::MatrixXd::Constant(N,M,1); //all 1;
    Mat(0,0)=1; Mat(1,1)=2; Mat(2,2)=3; Mat(3,3)=4; 
    Eigen::VectorXd Vec = Eigen::VectorXd::Zero(N*M);
    std::cout<<Mat<<std::endl;
    /*
     #######                                                         
     #       #        ##   ##### ##### ###### #    # # #    #  ####  
     #       #       #  #    #     #   #      ##   # # ##   # #    # 
     #####   #      #    #   #     #   #####  # #  # # # #  # #      
     #       #      ######   #     #   #      #  # # # #  # # #  ### 
     #       #      #    #   #     #   #      #   ## # #   ## #    # 
     #       ###### #    #   #     #   ###### #    # # #    #  ####  
                                                                             
    */
    //sequential
    for(int i=0; i<Mat.rows(); i++){
        for(int j=0; j<Mat.cols();j++){
            Vec(Mat.cols()*i+j)=Mat(i,j);
        }
    }
    std::cout << "seq"<<std::endl << Vec.transpose()<< std::endl;

    //parallel
    #pragma omp parallel for
    for(int i=0; i<Mat.rows(); i++){
        for(int j=0; j<Mat.cols();j++){
            Vec(Mat.cols()*i+j) = Mat(i,j);
        }
    }
    //index i,j loop内部で生成してるので自動的にprivate変数。

    std::cout << "parallel"<<std::endl << Vec.transpose() << std::endl;

    /*                                                                                                     
    #####   ####   ####   ####  # #####  #      ######     ####   ####  #    # ###### #      #  ####  ##### 
    #    # #    # #      #      # #    # #      #         #    # #    # ##   # #      #      # #    #   #   
    #    # #    #  ####   ####  # #####  #      #####     #      #    # # #  # #####  #      # #        #   
    #####  #    #      #      # # #    # #      #         #      #    # #  # # #      #      # #        #   
    #      #    # #    # #    # # #    # #      #         #    # #    # #   ## #      #      # #    #   #   
    #       ####   ####   ####  # #####  ###### ######     ####   ####  #    # #      ###### #  ####    #   
    */

    //multiple addition works just fine
    //if and only if it's not recurrent calculation.
    std::cout << "Add 1 then Add 2 to each element"<<std::endl;
    std::cout << "similar to grad making situation"<<std::endl;
    
    #pragma omp parallel for
    for(int i=0; i<Mat.rows(); i++){
        for(int j=0; j<Mat.cols();j++){
            Vec(Mat.cols()*i+j) += 1;
            Vec(Mat.cols()*i+j) += 2;
        }
    }
    std::cout << "parallel"<<std::endl << Vec.transpose() << std::endl;

    //adding locally defined value
    std::cout << "Add Mat(i,j) to each element"<<std::endl;   
    #pragma omp parallel for
    for(int i=0; i<Mat.rows(); i++){
        for(int j=0; j<Mat.cols();j++){
            double add = Mat(i,j);
            Vec(Mat.cols()*i+j) += add;
        }
    }
    std::cout << "parallel"<<std::endl << Vec.transpose() << std::endl;

    std::cout << "Add itself( Vec(self) ) to each element"<<std::endl;   
    #pragma omp parallel for
    for(int i=0; i<Mat.rows(); i++){
        for(int j=0; j<Mat.cols();j++){
            double add = Vec(Mat.cols()*i+j);
            Vec(Mat.cols()*i+j) += add;
        }
    }
    std::cout << "parallel"<<std::endl << Vec.transpose() << std::endl;

    return 0;
}