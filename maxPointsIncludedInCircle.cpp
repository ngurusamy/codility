/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


// Example program
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int solution(string &S, vector<int> & X, vector<int> & Y) {
    
    vector<char> tags;
    vector<int> tagsDis;
    
    int sameTagDis = 0;
    int noOfPoints = 0;
    int maxDis = INT_MIN;
    
    size_t N = X.size();
    vector<char> ::iterator itr;
    
    for(size_t i = 0; i < S.length() ; i++) {
        int tmp = 0;
        if(tags.size() == 0) {
            tags.push_back(S.at(i));
            tmp = sqrt((X[i] * X[i]) + (Y[i] * Y[i]));
            tagsDis.push_back(tmp);
            noOfPoints++;
        } else {
            
            itr = std::find(tags.begin(), tags.end(), S.at(i));
            //std::vector<char>::iterator itr = std::find(tags.begin(), tags.end(), S.at(i));
            
            //std::cout << "TAG : " << S.at(i) << "\n";
            
            if (itr != tags.end()) {
                int idx = std::distance(tags.begin(), itr);
                tmp = sqrt((X[i] * X[i]) + (Y[i] * Y[i]));
                tmp = std::max(tmp, tagsDis[idx]);
                maxDis = std::max(maxDis, tmp);
                //std::cout << " NOT ! : " << maxDis << " :: Dis " << tmp << "\n";
                tagsDis.push_back(tmp);
            } else {
                int tmpDis = sqrt((X[i] * X[i]) + (Y[i] * Y[i]));
                //std::cout << " I : " << i << " :: Dis : " << tmpDis << " :: Max Dis : "  << maxDis << " \n";
                tags.push_back(S.at(i));
                noOfPoints++;
            }
            
        }
    }
    
    noOfPoints = 0;
    for(size_t i = 0; i < N; i++) {
        int tmpDis = sqrt((X[i] * X[i]) + (Y[i] * Y[i]));
        if(maxDis > tmpDis) {
            noOfPoints++;
        }
    }
    
    //std::cout<< "TAGS SIZE : " << tags.size() << "\n";
    return noOfPoints;
}

int main()
{
  /*string S("ABDCA");
  vector <int> X {2, -1,-4, -3, 3};
  vector <int> Y {2, -2, 4, 1, -3};*/
  
  /*string S("ABB");
  vector <int> X {1, -2, 2};
  vector <int> Y {1, -2, 2};*/
  
  string S("ABDCAD");
  vector <int> X {2, -1,-4, -3, 3, 2};
  vector <int> Y {2, -2, 4, 1, -3, 2};
  
  int N = solution(S, X, Y);
  
  cout << "N : " <<  N << "\n";
}
