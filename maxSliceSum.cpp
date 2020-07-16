// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    double max = *std::max_element(A.begin(), A.end());
    
    if(max < 0)
        return max;
    size_t N = A.size();
    
    int max_ending = 0;
    int max_slice = 0;
    
    for(size_t i = 0; i < N; i++) {
        max_ending = std::max(0, max_ending + A[i]);
        max_slice = std::max(max_slice, max_ending);
    }
    
    return max_slice;
}

int solution_max_silce_sum(vector<int> & A) {
    size_t N = A.size();
    vector<int> sum(vector<int>);
    int max_slice_sum = INT_MIN;
    vector<vector<int>> sum_matrix(N, std::vector<int>(N, 0));
    
    for(size_t i = 0; i < N; i++) {
        sum_matrix[i][i] = A[i];
        max_slice_sum = std::max(max_slice_sum, sum_matrix[i][i]);
        for (size_t j = i + 1; j < N; j++) {
            sum_matrix[i][j] = sum_matrix[i][j - 1] + A[j];
            max_slice_sum = std::max(max_slice_sum, sum_matrix[i][j]);
        }
    }

    return max_slice_sum;
}
