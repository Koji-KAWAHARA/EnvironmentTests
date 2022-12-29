#include "omp_flag_control.hpp"
using namespace std;

int main(void){
    #ifdef USE_OMP
    omp_set_num_threads(200);
    #endif
    
    int N=10000;

    std::cout<<"sequential"<<endl;
    for(int i=0;i<N;i++){
        std::cout<<i<<endl;
    }
    std::cout<<endl<<endl;


    std::cout<<"true parallel"<<endl;
    #pragma omp parallel for
    for(int i=0;i<N;i++){
        std::cout<<i<<endl;
    }
    std::cout<<endl<<endl;
    /*
    #pragma omp parallel
    {
        std::cout<<"thread"<<endl;
    }
    */
    
    #ifdef USE_OMP
        std::cout<<"parallel works"<<endl;
        #pragma omp parallel for
    #endif
    for(int i=0;i<N;i++){
        cout<<i<<endl;
    }
    cout<<endl<<endl;

    #ifdef USE_OMP
        std::cout<<"parallel fails on this end as well"<<endl;
        #pragma omp parallel for
        for(int i=0;i<N;i++){
    #elif
        for(int i=0;i<N;i++){
    #endif    
        std::cout<<i<<endl;
    }
    std::cout<<endl<<endl;
    
    return 0;
}

