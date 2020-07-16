// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> diskStartPoint(A.size());
    vector<int> diskEndPoint(A.size());
    
    size_t noOfDisks = A.size();
    int openDisks = 0;
    int interSections = 0;
    
    int endPointIdx = 0;
    
    for(size_t i = 0; i < noOfDisks; i++) {
        diskStartPoint[i] = i - A[i];
        diskEndPoint[i] = i + A[i];
    }
    
    std::sort(diskStartPoint.begin(), diskStartPoint.end());
    std::sort(diskEndPoint.begin(), diskEndPoint.end());
    
    for(size_t i = 0; i < noOfDisks;) {
        
        if(diskStartPoint[i] <= diskEndPoint[endPointIdx]) {
            interSections += openDisks;
            openDisks++;
            i++;
        } else {
            endPointIdx++;
            openDisks--;
        }
    }
    
    return interSections;
}