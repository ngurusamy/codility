// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// Example program
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>


int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
 
  if (N == 0)
    return 0;

 //std::cout << " N = " << N << std::endl;
  
 /* if (n > 2147483647)
  {
      std::cout << "n is not in the range 1.....2147483647 - > " << n << std::endl;
      return 0;
  }*/
    
  int temp = N;
  int count = 0;
  while( temp > 0 )
  {
    
    if( (temp & 1) == 1)
    {
        int tmpCount = 0;
        while (temp > 0)
        {
            temp = temp >> 1;
            
            if( (temp & 1) == 0)
            {
                //count++;
                tmpCount++;
                //std::cout << "Tmp Count : " << tmpCount << std::endl;
            }
            else
            {
                count = std::max(count, tmpCount);
                break;
            }
        
        }
        
        //count++;
    }
    else
    {
        temp = temp >> 1;
    }
 
  }
  
  return count;
}




int main()
{
  int n = 34;
  
  std::cout << "Longest No of Consecutive 0s " << solution(n) << "!\n";
  
  std::cout << "INT MAX : " << INT_MAX << std::endl;
}