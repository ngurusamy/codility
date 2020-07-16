int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    size_t N = A.size();
    int max_ending = 0;
    int max_profit = 0;
    
    if(N < 2) {
        return 0;
    }
    
    vector<int> delta(N - 1,0);
    
    for(size_t i = 1; i < N; i++) {
        delta [ i - 1] = A[i] - A[i - 1];
    }
    
    for(size_t i = 0; i < delta.size(); i++) {
        max_ending = std::max(0, max_ending + delta[i]);
        max_profit = std::max(max_profit, max_ending);
    }
    
    return max_profit;
}

/*********
// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        int min = Integer.MAX_VALUE;
        int max = 0;
        
        for(int i = 0 ; i < A.length ; i++ ){
            min = A[i] < min ? A[i]:min;
            max = A[i] - min > max ? A[i] - min : max;
        }
        return max;
    }
}


int solution(vector<int> &A) {
	int min = INT_MAX;
	int max = 0;
	
	size_t N = A.size();
	
	for(size_t i = 0; i < N; i++) {
		min = A[i] < min ? A[i] : min;
		max = A[i] - min > max ? A[i] - min : max;
	}
	
	return max;
}



**********/