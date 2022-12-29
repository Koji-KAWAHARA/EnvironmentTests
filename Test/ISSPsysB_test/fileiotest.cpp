#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main(int argc, char* argv[]){
 int i = atoi(argv[1]);
 int j = atoi(argv[2]);
 //char fname[100];
 //sprintf(fname,“%d-%dtest.txt”,i,j);
 string fname;
 fname = to_string(i)+"-"+to_string(j)+"test.txt";
 cout << fname <<endl;
  ofstream file1;
  file1.open(fname);
  if(!file1){
  cout<<"filenotopen : "<<fname<<endl;
  exit(1);
  }
  file1 << i << ", "<< j <<endl;
  file1.close();
}