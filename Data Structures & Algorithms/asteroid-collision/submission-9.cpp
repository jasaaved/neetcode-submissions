#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for(int asteroid : asteroids){

            if(st.empty()){
                st.push(asteroid);
            }
            
            else if(st.top() > 0 && st.top() + asteroid == 0){
                st.pop();
            }

            else if((st.top() ^ asteroid) >= 0){
                st.push(asteroid);
            }

            else{
                while(!st.empty() && st.top() >= 0 && st.top() * asteroid < 0 && st.top() < abs(asteroid) ){
                    st.pop();
                }

                if(st.empty() || (!st.empty() && abs(asteroid) > st.top())){
                    st.push(asteroid);
                }

                else if(!st.empty() && abs(asteroid) == st.top()){
                    st.pop();
                }

            }

        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        int left = 0;
        int right = static_cast<int>(ans.size()) - 1;
        while(left < right){
            swap(ans[left++], ans[right--]);
        }

        return ans;
    }
};