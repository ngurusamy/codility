// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    std::stack<int> leaders;
    
    size_t N = A.size();
    
    if(N == 0) {
        return -1;
    }
    
    leaders.push(A[0]);
    
    for(size_t i = 1; i < N; i++) {
        
        if(!leaders.empty() && leaders.top() != A[i]) {
            leaders.pop();
        } else {
            leaders.push(A[i]);
        }
    }
    
    if(leaders.empty()) {
        return -1;
    }
    
    int leader = leaders.top();
    
    int count = 0;
    int index = -1;
    
    for(size_t i = 0; i < N; i++) {
        if(A[i] == leader) {
            count++;
            index = i;
        }
    }
    
    if(!(double(count) > double(N/2))) {
        return -1;
    }
    
    return index;

}