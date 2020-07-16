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
#include <map>

using namespace std;

map <char, int> dnaSeq;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    
    vector <int> res;
    int s = 0;
    int e = 0;
    
    for (int i = 0; i < P.size(); i++) {
        
        int minCost = INT_MAX;
        
        s = P[i];
        e = Q[i];
        
        for(int j = s; j <= e; j++) {
            minCost = std::min(minCost, dnaSeq)
        }
    }
    
}

int main()
{
    //vector<int> vect{2, 3, 4, 5, 6};
    //vector<int> vect{-3, -1};
    dnaSeq.insert(pair<char, int>('A', 1));
    dnaSeq.insert(pair<char, int>('C', 2));
    dnaSeq.insert(pair<char, int>('G', 3));
    dnaSeq.insert(pair<char, int>('T', 4));

    return 0;    
}


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<vector<int> > chs(S.size()+1,vector<int>(4,0));
    
    for(unsigned int i=0; i<S.size(); i++){
        for(int j=0; j<4; j++)
            chs[i+1][j] = chs[i][j];
        switch(S[i]){
            case 'A': chs[i+1][0]=chs[i][0]+1; break;
            case 'C': chs[i+1][1]=chs[i][1]+1; break;
            case 'G': chs[i+1][2]=chs[i][2]+1; break;
            case 'T': chs[i+1][3]=chs[i][3]+1; break;
            default: break;
        }
    }
    vector<int> res;
    for(unsigned int i =0; i<P.size(); i++){
           int j;
           for( j=0; j<4; j++){
                if(chs[Q[i]+1][j]-chs[P[i]][j]!=0)
                    break;
           }
           res.push_back(j+1);
    }
    return res;

}





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
#include <map>
#include <string>

using namespace std;

//map <char, int> dnaSeq;

vector<int> solution1(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++11
    vector<vector<int> > chs(S.size()+1,vector<int>(4,0));
    
    for(int i=0; i<S.size(); i++){
        for(int j=0; j<4; j++)
            chs[i+1][j] = chs[i][j];
        switch(S[i]){
            case 'A': chs[i+1][0]=chs[i][0]+1; break;
            case 'C': chs[i+1][1]=chs[i][1]+1; break;
            case 'G': chs[i+1][2]=chs[i][2]+1; break;
            case 'T': chs[i+1][3]=chs[i][3]+1; break;
            default: break;
        }
    }
    
    
    for(int i = 0; i <= S.size(); i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << chs[i][j] << " ";
        }
        
        std::cout << std::endl;
    }
    
    vector<int> res;
    for(int i =0; i<P.size(); i++){
           int j;
           for( j=0; j<4; j++){
                if(chs[Q[i]+1][j]-chs[P[i]][j]!=0)
                    break;
           }
           res.push_back(j+1);
    }
    return res;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
 // write your code in C++11 (g++ 4.8.2)
    vector<int> pre_sum_A;
    vector<int> pre_sum_C;
    vector<int> pre_sum_G;
    vector<int> pre_sum_T;
 
    int cnt_A = 0;
    int cnt_C = 0;
    int cnt_G = 0;
    int cnt_T = 0;
 
    for (size_t i = 0; i < S.size(); i++) {
        if (S[i] == 'A') cnt_A++;
        else if (S[i] == 'C') cnt_C++;
        else if (S[i] == 'G') cnt_G++;
        else if (S[i] == 'T') cnt_T++;
 
        pre_sum_A.push_back(cnt_A);
        pre_sum_C.push_back(cnt_C);
        pre_sum_G.push_back(cnt_G);
        pre_sum_T.push_back(cnt_T);
    }
    
    std::cout << " A : " << pre_sum_A.size() << " :: C : " << pre_sum_C.size() << " :: G : " << pre_sum_G.size() << " :: T : " 
        << pre_sum_T.size() << std::endl;
        
    for(int i = 0 ; i < S.size(); i++) {
        std::cout << " A : " << pre_sum_A[i] << " :: C : " << pre_sum_C[i] << " :: G : " << pre_sum_G[i] << " :: T : " 
        << pre_sum_T[i] << std::endl;
    }
 
    vector<int> result(P.size());
    for (int i = 0; i < int(P.size()); i++) {
        int A = (S[P[i]] == 'A') ? 1 : 0;
        int C = (S[P[i]] == 'C') ? 1 : 0;
        int G = (S[P[i]] == 'G') ? 1 : 0;
        int T = (S[P[i]] == 'T') ? 1 : 0;
        if (pre_sum_A[Q[i]] - pre_sum_A[P[i]] + A > 0) result[i] = 1;
        else if (pre_sum_C[Q[i]] - pre_sum_C[P[i]] + C > 0) result[i] = 2;
        else if (pre_sum_G[Q[i]] - pre_sum_G[P[i]] + G > 0) result[i] = 3;
        else if (pre_sum_T[Q[i]] - pre_sum_T[P[i]] + T > 0) result[i] = 4;
        else result[i] = 5;
    }
 
    return result;
}

int main()
{
    //vector<int> vect{2, 3, 4, 5, 6};
    //vector<int> vect{-3, -1};
    /*dnaSeq.insert(pair<char, int>('A', 1));
    dnaSeq.insert(pair<char, int>('C', 2));
    dnaSeq.insert(pair<char, int>('G', 3));
    dnaSeq.insert(pair<char, int>('T', 4));
    */
    
    vector<int> P {2, 5, 0};
    vector<int> Q {4, 5, 6};

    std::string pattern ("CAGCCTA");
    //std::string pattern ("GGGGGGG");
    vector <int> res = solution(pattern, P, Q);
    
    for(int i = 0; i < res.size(); i++) {
        //std::cout << res[i] << " ";
    }
    
    std::cout << std::endl;
    return 0;    
}
