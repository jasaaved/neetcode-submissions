#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for(int asteroid : asteroids){

            while(!st.empty() && st.top() > 0 && asteroid < 0 && st.top() < abs(asteroid)){
                st.pop();
            }

            if(st.empty() || st.top() < 0 || asteroid > 0){
                st.push(asteroid);
            }

            else if(st.top() == abs(asteroid)){
                st.pop();
            }

        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};