// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution (vector<int> & A) {
    size_t N = A.size();
    int max_double_slice = 0;
    vector<int> ending_here (N, 0);
    vector<int> starting_here (N, 0);
    
    for(size_t i = 1; i < N; i++) {
        ending_here[i] = std::max(0, ending_here[i - 1] + A[i]);
    }
    
    for(int i = N - 2 ; i > 0; i--) {
        starting_here[i] = std::max(0, starting_here[i + 1] + A[i]);
    }
    
    for(size_t i = 1; i < N - 1; i++) {
        max_double_slice = std::max(max_double_slice, starting_here[i + 1] + ending_here[i - 1]);
    }
    
    return max_double_slice;
}

int main()
{
    vector<int> vect{3, 2, 6, -1, 4, 5, -1, 2};
    
    int res = solution(vect);
    
    std::cout << "Max Double Slice : " << res << std::endl;
    return 0;
}
