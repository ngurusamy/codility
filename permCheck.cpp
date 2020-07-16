// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int ret = 0;
    
    std::sort(A.begin(), A.end());
    
    int size = A.size();
    
   // int eleSum = 0;
    //int idxSum = 0;
    
    for(int i = 0; i < size; i++) {
        if(A[i] ^ (i + 1)) {
            ret = 0;
            break;
        } else {
            ret = 1;
        }
    }
    
    return ret;
}