// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

struct FishDetails {
    int weight;
    int dir;
};

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    std::stack<FishDetails> fishStack;
    //std::stack<int> dir;
    
    size_t N = A.size();
    
    for (size_t i = 0 ; i < N; i++) {
        
        if(fishStack.empty()) {
            FishDetails fish{A[i], B[i]};
            fishStack.push(fish);
            continue;
        }
        
        bool eaten = false;
        
        do {
            
            FishDetails lastFish = fishStack.top();
            
            if(lastFish.dir == B[i]) {
                break;
            }
            
            if(!lastFish.dir) {
                break;
            }
            
            eaten = false;
            
            if(A[i] > lastFish.weight) {
                fishStack.pop();
            } else {
                eaten = true;
            }
        } while(!fishStack.empty() && !eaten);
        
        if(!eaten) {
            
            FishDetails fish{A[i], B[i]};
            fishStack.push(fish);
        }
        
    }
    
    return (fishStack.size());

}