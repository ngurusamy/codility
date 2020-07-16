// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A)
{
    int ret = 0;
    
	vector<int> temp(A);
	
	vector<int> :: iterator itr;
		
	//sort(temp.begin(),temp.end());
	
	for(itr = A.begin(); itr != A.end(); itr++)
	{
	    /*int occurance = count(temp.begin(), temp.end(), *itr);
	    if(occurance % 2 != 0)
	    {
	        ret = *itr;
	        break;
	    }*/
	    
	    ret = ret ^ *itr;
	}
	
    return ret;
	
}

int main()
{
    vector<int> vect{ 3, 2, 1, 5, 3, 5, 2 };
    int oddNum = solution(vect);
    
   vector<int>:: iterator ptr;
   /*sort(vect.begin(),vect.end());
   for(ptr = vect.begin(); ptr < vect.end(); ptr++)
     std::cout  << *ptr << " ";*/
     
  std::cout << "Odd Num is : " << oddNum << std::endl;
}
