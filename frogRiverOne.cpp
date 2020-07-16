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
#include <set>

using namespace std;

int solution(int X, vector<int> &A)
{
   /* int sec = INT_MIN;
    
    vector<int> :: iterator itr;
    
    if(A.empty()) 
    {
        std::cout << "Vector is empty" << std::endl;
        return -1;
    }
    
   
    for(int i = 1; i <= X; i++) {
        itr = std::find(A.begin(), A.end(), i);
        int temp = -1 ;
        
        if(itr == A.end())
        {
            std::cout << " Pos : " << i << " not found " <<std::endl;
            sec = -1;
            break;
        }
        else
        {
            temp = std::distance(A.begin(), itr);
            sec = std::max(temp, sec);
        }
    }
    
    return sec; */
    
    set<int> final;
    for(unsigned int i =0; i< A.size(); i++){
        final.insert(A[i]);
        if(final.size() == X) return i;
    }
    return -1;
    
}

int main()
{
    vector<int> vect{1, 3, 1, 3, 2, 1, 3};
    int secs = solution(3, vect);
    
    std::cout << "Seccond is : " << secs << std::endl;
}
