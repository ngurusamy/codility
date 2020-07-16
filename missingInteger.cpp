// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int n = A.size();
    
    vector<bool> present (n, false);
    
    for(int i = 0; i < n; i++) {
        if(A[i] > 0 && A[i] <= n) {
            present[A[i] - 1] = true;
        }
    }
    
    for(int i = 0; i <= n; i++) {
        if(present[i] == false) {
            return i + 1;
        }
    }
    
    return n+1;
}