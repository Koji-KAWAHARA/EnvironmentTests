#include "BasicOpr.hpp"

//#include <Eigen/Core>       //core
//#include <Eigen/Dense>      //for dense matrix

using namespace Eigen;
using namespace std;

//乱数のための宣言
std::random_device rd;
std::mt19937 gen(rd());
double rand_double(const double min,const double max){
  std::uniform_real_distribution dist(min,max);
  return dist(gen);
}

//rk45 parameters
//rk(0,:) is for evaluating residue (5th_order_prediction - 4th_order_prediction).
//rk(1,:) is for evaluating 4th_order_prediction itself.
//else is for determination of prediction for each step.
MatrixXd rk = []{
    Eigen::MatrixXd tmp(7,7);
    tmp(0,1)= 1/360.0;    tmp(0,2)=0;            tmp(0,3)=-128/4275.0;    tmp(0,4)=-2197/75240.0; tmp(0,5)=1/50;       tmp(0,6)=2/55.0;
    tmp(1,1)= 25/216.0;   tmp(1,2)=0;            tmp(1,3)=1408/2565.0;    tmp(1,4)=2197/4104.0;   tmp(1,5)=-1.0/5.0;   tmp(1,6)=0;
    tmp(2,1)=0.25;
    tmp(3,1)=3.0/32.0;    tmp(3,2)=9.0/32.0;
    tmp(4,1)=1932/2197.0; tmp(4,2)=-7200/2197.0; tmp(4,3)=7296/2197.0;
    tmp(5,1)=439/216.0;   tmp(5,2)=-8.0;         tmp(5,3)=3680/513.0;     tmp(5,4)=-845/4104.0;
    tmp(6,1)=-8.0/27.0;   tmp(6,2)=2.0;          tmp(6,3)=-3544.0/2565.0; tmp(6,4)=1859/4104.0;   tmp(6,5)=-11.0/40.0;
    return tmp;
}();

//for debug
void flag(string message){std::cout<<message<<endl;}

// a mod b, but answer is always positive (ex posmod(-5,3) = 1, not -2)
INT posmod(INT a, INT b){
  return (a - floor((float)a / (float)b) * b);
}

MatrixXd Printeye(int n){
  MatrixXd tmp;
  tmp = MatrixXd::Identity(n,n);
  return tmp;
}


//read matrix from a file. "#" is comment indicator
//https://stackoverflow.com/questions/20786220/eigen-library-initialize-matrix-with-data-from-file-or-existing-stdvector
MatrixXd ReadMatrix(const string filename){
  int cols = 0;
  int rows = 0;
  vector<double> tmpvec;
  // Read numbers from file into buffer.
  ifstream infile(filename);
  if (!infile){
    cout << "error >> failed to open the matrix data file." << endl;
    exit(1);
  }
  cout<<"fileopen:"<<filename<<"  ";
  
  //OK before here
  double num;
  while (! infile.eof()){
    string line;
    getline(infile, line);
    if(line[0]!= '#'){    //skip comment line 
      int temp_cols = 0;
      stringstream stream(line);
      while(stream >> num){
        tmpvec.push_back(num);
        temp_cols++;
      }
      if (temp_cols == 0){continue;}
      if (cols == 0){cols = temp_cols;}
      rows++;
    }
  }
  infile.close();

  std::cout <<"size("<< rows <<" , "<<cols <<")"<< endl;
  // Populate matrix with numbers.
  MatrixXd result = MatrixXd::Zero(rows,cols);
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
        result(i,j) = tmpvec[ cols*i+j ];
    }
  }
  return result;
}


//convert string to integer vector. (delimiter of the string should be " ")
Eigen::Vector<INT,Eigen::Dynamic> string_to_ivector(std::string str){
  vector<INT> tmp;
  string delimiter = ",";
  size_t pos;
  while((pos=str.find(delimiter))!=string::npos){
    tmp.push_back(stoi(str.substr(0,pos)));
    str.erase(0,pos + delimiter.length());
  }
  return Eigen::Map<Eigen::Vector<INT,Dynamic>, Eigen::Unaligned>(tmp.data(), tmp.size());
}

double find_max_element(const Eigen::MatrixXd mat){
  double tmp=mat(0,0);
  for(int i=0;i<mat.rows();i++){
    for(int j=0;i<mat.cols();j++){
      if(tmp<mat(i,j)){tmp=mat(i,j);}
    }
  }
  return tmp;
}
int find_max_element(const Eigen::MatrixXi mat){
  int tmp=mat(0,0);
  for(int i=0;i<mat.rows();i++){
    for(int j=0;i<mat.cols();j++){
      if(tmp<mat(i,j)){tmp=mat(i,j);}
    }
  }
  return tmp;
}

