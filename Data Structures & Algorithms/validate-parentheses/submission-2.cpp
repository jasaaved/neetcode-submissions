#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> right_stack;
        stack<char> left_stack;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                left_stack.push(c);
            }
            else{
                if(left_stack.empty()){
                    return false;
                }
                else if(c == ')' && left_stack.top() != '('){
                    return false;
                }
                else if(c == '}' && left_stack.top() != '{'){
                    return false;
                }
                else if(c == ']' && left_stack.top() != '['){
                    return false;
                }

                left_stack.pop();
            }
        }
        
        return left_stack.empty();
    }
};
