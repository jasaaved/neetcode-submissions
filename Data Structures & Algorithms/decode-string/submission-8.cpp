#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(const string& s) const noexcept {
        stack<int> freq;
        stack<string> s_st;

        string num;
        string word;

        for(char c : s) {
            if(c == '[') {
                freq.push(stoi(num));
                num = "";

                s_st.push(word);
                word = "";
            }

            else if(c == ']') {
                const int n = freq.top();
                freq.pop();

                string temp = s_st.top();
                s_st.pop();

                for(int i = 0; i < n; ++i) {
                    temp += word;
                }

                swap(temp, word);
            }

            else if(isdigit(c)) {
                num += c;
            }

            else if (isalpha(c)) {
                word += c;
            }
        }

        return word;
    }
};