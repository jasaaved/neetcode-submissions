#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(vector<string>& tokens) { 
        stack<int> st;
        
        for(const string& s : tokens){
            if(s == "+" || s == "-" 
            || s == "*" || s == "/"){
                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                if(s == "+"){
                    st.push(left + right);
                }

                else if(s == "-"){
                    st.push(left - right);
                }

                else if(s == "*"){
                    st.push(left * right);
                }

                else{
                    st.push(left / right);
                }
            }

            else{
                st.push(stoi(s));
            }
        }

        return st.top();
    }


};

