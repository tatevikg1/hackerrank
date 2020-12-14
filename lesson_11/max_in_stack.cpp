#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    std::vector<int> numbers;
    int N, type;
    cin >> N;  
    
    for(int i = 0; i < N; ++i){
        cin >> type;

        switch (type) {
        case 1:
            int x;
            cin >> x;
            numbers.push_back(x);
            break;
        case 2:
            numbers.pop_back();
            break;
        case 3:
            auto max = std::max_element(numbers.begin(), numbers.end()) ;
            cout << *max << "\n";
        }
        
    }   
    return 0;
}
