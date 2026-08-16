#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        for(const string& s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                calc(s);
            }

            else{
                st.push(stoi(s));
            }
        }

        return st.top();
    }

private:
    stack<int> st;
    void calc(const string& op){
        int final = st.top();
        st.pop();

        if(op == "+"){
            final += st.top();  
        }

        else if(op == "-"){
            final = st.top() - final;
        }

        else if(op == "*"){
            final *= st.top();
        }

        else{
            final = st.top() / final;
        }

        st.pop();
        st.push(final);
    }
};

