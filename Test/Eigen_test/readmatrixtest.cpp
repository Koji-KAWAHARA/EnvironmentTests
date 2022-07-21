//#include <getopt.h> //to use getopt function for parameter setting.
//#include <math.h>
//#include <mkl.h>
//#include <random>
//#include <algorithm>
//#include <cmath>
//#include <tuple> //to use tuple return from function
#include "BasicOpr.hpp"
using namespace std;
using namespace Eigen;

int main(void){
  cout<<"hello"<<endl;
  string fname = "./matrix_read_test.dat";
  cout << posmod(1,10)<<endl;
  cout << fname << endl;

  MatrixXd result;
  
  result = Printeye(3);
  cout <<result <<endl;
  cout<<"flag1"<<endl;

  result = ReadMatrix(fname);
  cout << result << endl;
  cout<<"flag2"<<endl;

  VectorXi index;
  index = string_to_ivector("1 10 100 1000 2022");
  cout << index;
}
