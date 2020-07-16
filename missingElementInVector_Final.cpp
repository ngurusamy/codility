// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int missingElement = 0;
    int noOfElement = A.size();
    
    if(noOfElement == 0)
        return 1;
	if(noOfElement == 1) {
		if(A[0] > 0 && A[0] !=1)
			return 1;
		
		return (A[0] + 1);
    }
    sort(A.begin(), A.end());
	
	if(A[0] != 1)
		return 1;
    
	vector <int> :: iterator itr;
	
    for( itr = A.begin(); itr != A.end(); itr++) {
		if((itr + 1) == A.end())
		{
			return (*itr + 1);
		}
        if((*(itr + 1) - *itr) > 1) {
            missingElement = *itr + 1;
            break;
        }
    }
    
    return missingElement;

}


int solution_final(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    long noOfElement = A.size();
    long total = (noOfElement + 1) * (noOfElement + 2)/2;
    long sum = 0;
    
    for(auto i: A) 
    {
        sum += i;
    }
    
	return (int) total - sum;

}

