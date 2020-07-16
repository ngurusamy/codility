// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int triangle = 0;
    std::sort(A.begin(), A.end());
    
    for(size_t i = 2; i < A.size(); i++) {
        if(A[i - 2] > 0 && A[i - 2] > (A[i] - A[i - 1])) {
            triangle = 1;
        }       
    }
    
    return triangle;
}