/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    std::stack<int> leaders;
    int equiLeader = 0;
    
    size_t N = A.size();
    
    leaders.push(A[0]);
    
    for(size_t i = 1; i < N; i++) {
        if(!leaders.empty() &&  leaders.top() != A[i]) {
            leaders.pop();
        } else {
            leaders.push(A[i]);
        }
    }
    if(leaders.empty()) {
        return 0;
    }
        
    int leader =  leaders.top();
        
    int count = 0;
        
    for (size_t i = 0; i < N; i++) {
        if(leader == A[i]) {
            count++;
        }
    }
        
    if(!(double(count) > double(N/2))) {
        return 0;
    }
        
    int countX = 0;
    int countY = 0;
    int sizeX = 0;
    int sizeY = 0;
        
    for(size_t i = 0; i < N; i++) {
        if(leader == A[i]) {
            countX++;
        }
            
        countY = count - countX;
            
        sizeX = i + 1;
        sizeY = N -sizeX;
            
        double halfSizeX = ((double)(sizeX))/2;
        double halfSizeY = ((double)(sizeY))/2;
            
        if ((countX > halfSizeX) && (countY > halfSizeY)) {
            equiLeader++;
        }
    }
    return equiLeader;
}


int main()
{
    vector<int> vect{4, 3, 4, 4, 4, 2};
    
    int res = solution(vect);
    
    std::cout << "No of Equilears : " << res << std::endl;
    return 0;
}
