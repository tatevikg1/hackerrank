#include <iostream>


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    unsigned int N;
    std::cin >> N; 
    int* A = new int[N];
    
    for (int i = 0; i < N; ++i){
        std::cin >> A[i];
    }
    
    for (int i = N -1; i >= 0; --i){
        std::cout << A[i] << " ";
    }
    
    delete[] A;
    return 0;
}
