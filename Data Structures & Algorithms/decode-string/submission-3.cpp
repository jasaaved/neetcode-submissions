#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> freq;
        stack<string> s_st;
        string num;
        string current;


        for(char c : s){
            if(c == '['){
                freq.push(stoi(num));
                num = "";
                s_st.push(current);
                current = "";
            }

            else if(c == ']'){
                int n = freq.top();
                freq.pop();
                string s = current;
                current = s_st.top();
                s_st.pop();

                for(int i = 0; i < n; ++i){
                    current += s;
                }
            }
            
            else if(isdigit(c)){
                num += c;
            }

            else if(isalpha(c)){
                current += c;
            }
        }

        return current;
    }
};