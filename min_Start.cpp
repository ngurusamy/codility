int solution(vector<int> &A) {
 // write your code in C++11 (g++ 4.8.2)
 vector<int> pre_sum(A.size());
 int pre_s = 0;

 for (size_t i = 0; i < A.size(); i++) {
        pre_s += A[i];
        pre_sum[i] = pre_s;
    }

 int start = 0;
 int end = 1;
 int min_start = start;
 double min_avg = double(pre_sum[end] - pre_sum[start] + A[start]) / (end - start + 1);

 for (size_t i = 1; i < A.size(); i++) {
 double avg = double(pre_sum[i] - pre_sum[start] + A[start]) / (i - start + 1);

 if (avg < min_avg) {
            min_avg = avg;
            min_start = start;
        }

 if (A[i] < min_avg) {
            start = i;
        }

    }

 return min_start;
}


/**********************************************************


    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8
	
Presum:

4 6 8 13 14 19 27
0 1 2 03 04 05 06

Start : 0 :: End : 1 :: Min_Start : 0 :: Min_Avg : 3

Start : 0 :: End : 1 :: Min_Start : 0 :: Avg : 3
Start : 1 :: End : 1 :: Min_Start : 0 :: Min_Avg : 3

Start : 1 :: End : 2 :: Min_Start : 0 :: Avg : 2
Start : 1 :: End : 2 :: Min_Start : 1 :: Min_Avg : 2

Start : 1 :: End : 3 :: Min_Start : 1 :: Avg : 3
Start : 1 :: End : 3 :: Min_Start : 1 :: Min_Avg : 2

Start : 1 :: End : 4 :: Min_Start : 1 :: Avg : 2.5
Start : 4 :: End : 4 :: Min_Start : 1 :: Min_Avg : 2

Start : 4 :: End : 5 :: Min_Start : 1 :: Avg : 3
Start : 4 :: End : 5 :: Min_Start : 1 :: Min_Avg : 2

Start : 4 :: End : 6 :: Min_Start : 1 :: Avg : 4.66667
Start : 4 :: End : 6 :: Min_Start : 1 :: Min_Avg : 2

Min_Start : 1

**********************************************************/


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int>pre_sum(A.size());
    
    int pre_s = 0;
    
    for(size_t i = 0; i < A.size(); i++) {
        pre_s += A[i];
        pre_sum[i] = pre_s;
    }
    
    int start = 0;
    int end = 1;
    int min_start = start;
    double min_avg = double(pre_sum[end] - pre_sum[start] + A[start]) / (end - start + 1);
    
    for (size_t i = 0; i < A.size(); i++) {
        double avg = double(pre_sum[i] - pre_sum[start] + A[start]) / ( i - start + 1);
        
        if(avg < min_avg) {
            min_avg = avg;
            min_start = start;
        }
        
        if (A[i] < min_avg) {
            start = i;
        } 
    }
    
    return min_start;
}



int solution(vector<int> &A) {
 // write your code in C++11 (g++ 4.8.2)
 vector<int> pre_sum(A.size());
 int pre_s = 0;

 for (size_t i = 0; i < A.size(); i++) {
        pre_s += A[i];
        pre_sum[i] = pre_s;
    }

 int start = 0;
 int end = 1;
 int min_start = start;
 double min_avg = double(pre_sum[end] - pre_sum[start] + A[start]) / (end - start + 1);

 for (size_t i = 1; i < A.size(); i++) {
 double avg = double(pre_sum[i] - pre_sum[start] + A[start]) / (i - start + 1);

 if (avg < min_avg) {
            min_avg = avg;
            min_start = start;
        }

 if (A[i] < min_avg) {
            start = i;
        }

    }

 return min_start;
}


