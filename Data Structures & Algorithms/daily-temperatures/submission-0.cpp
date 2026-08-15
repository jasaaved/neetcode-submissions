#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = static_cast<int>(temperatures.size());
        vector<int> result(n, 0);
        stack<int> st;

        for(int i = 0; i < n; ++i){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                result[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }
        
        return result;
    }
};
