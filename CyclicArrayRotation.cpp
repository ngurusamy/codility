// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void reverse (vector<int> &A, int low, int high)
{
    for(int i = low, j = high; i < j; i++, j--)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> result(A);
	
    if( K <= 0)
        return result;
	
	if( A.size() == 0)
		return result;
	
	if(K >= (int)A.size())
	{
		K %= A.size();
		/*reverse(result, 0, result.size() - 1);
		return result;*/
	}
    

        
    reverse(result, result.size() - K, result.size() - 1 );
    
    reverse(result, 0, result.size() - K - 1 );
    
    reverse(result, 0, result.size() - 1);
    
    return result;

}
