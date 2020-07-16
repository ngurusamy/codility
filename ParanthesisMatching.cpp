// you can use includes, for example:
// #include <algorithm>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    std::stack<char> strStack;
    char c;
    
    for(size_t i = 0; i < S.length(); i++) {
        if(S[i] == '{' || S[i] == '(' || S[i] == '[') {
            strStack.push(S.at(i));  
            continue;
        }
        
        if(strStack.empty())
            return 0;
            
        switch(S[i]) {
            case ')':
                c = strStack.top();
                strStack.pop();
                if(c == '{' || c == '[')
                    return 0;
                break;
            case '}':
                c = strStack.top();
                strStack.pop();
                if(c == ')' || c == '[')
                    return 0;
                break;
            case ']':
                c = strStack.top();
                strStack.pop();
                if(c == '{' || c == '(')
                    return 0;
                break;
        }
    }
    
    return (strStack.empty());

}