/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <math.h>

using namespace std;

int addSubArray(vector<int> &A, int low, int high){
    
    int sum = 0;
    for(int i = low; i <= high; i++) {
        sum += A[i];
    }
    
    return sum;
}

int solution(vector<int> &A)
{
    int minEqulibrium = INT_MAX;
    
    int sumRight = 0;
    int sumLeft = 0;
    
    int size = A.size();
    
    for(int i = 1; i < size; i++) {
        sumRight += A[i];
    }
    
    sumLeft = A[0];
    
    minEqulibrium = std::min(minEqulibrium, abs(sumLeft - sumRight));
    
    for(int i = 1; i < size - 1; i++) {
        sumRight -= A[i];
        sumLeft += A[i];
        
        minEqulibrium = std::min(minEqulibrium, abs(sumLeft - sumRight));
    }

    return minEqulibrium;
	
}

int main()
{
    vector<int> vect{3, 1, 2, 4, 3 };
    int min = solution(vect);
    
    std::cout << "Min is : " << min << std::endl;
}
