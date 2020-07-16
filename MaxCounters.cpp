// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> res (N, 0);
    
    int curMaxCount = 0;
	int lastIncrease = 0;
    
    vector <int> :: iterator itr;
    
    for(itr = A.begin(); itr != A.end(); itr++) {
        if(*itr > N) {
            lastIncrease = curMaxCount;
        } else {
			res[*itr - 1] = std::max(res[*itr - 1], lastIncrease);
            res[*itr - 1] += 1;
            curMaxCount = std::max(curMaxCount, res[*itr - 1]);
        }
    }
    
	for(int i=0; i<N; i++){
		res[i] = std::max(res[i], lastIncrease);
	}
    return res;

}