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
    
    for( int i = 0; i < noOfElement; i++) {
        if((A[i + 1] - A[i]) > 1) {
            missingElement = A[i] + 1;
            break;
        }
		else
		{
			
		}
    }
    
    return missingElement;

}
