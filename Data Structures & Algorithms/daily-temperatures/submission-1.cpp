#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = static_cast<int>(temperatures.size());
        vector<int> result(n, 0);
        stack<int> st;
        int tp;

        for(int i = 0; i < n; ++i){
            tp = st.top();
            while(!st.empty() && temperatures[i] > temperatures[tp]){
                result[tp] = i - tp;
                st.pop();
                tp = st.top();
            }

            st.push(i);
        }
        
        return result;
    }
};
