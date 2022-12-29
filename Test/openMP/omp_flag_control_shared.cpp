#include "omp_flag_control.hpp"
using namespace std;

int main(void){
    #ifdef USE_OMP
    omp_set_num_threads(200);
    #endif
    
    int N=10000;

    std::cout<<"sequential"<<endl;
    int a=0;
    for(int i=0;i<N;i++){
        a+=i;
    }
    std::cout<<a<<endl;
   
    a=0;
    #ifdef USE_OMP
        std::cout<<"shared mem"<<endl;
        #pragma omp parallel for shared(a)
    #endif
    for(int i=0;i<N;i++){
        a+=i;
    }
    cout<<a<<endl;

    a=0;
    #ifdef USE_OMP
        std::cout<<"reduction mem"<<endl;
        #pragma omp parallel for reduction(+:a)
    #endif
    for(int i=0;i<N;i++){
        a+=i;
    }
    cout<<a<<endl;
    return 0;
}

