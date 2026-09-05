#include <algorithm>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = static_cast<int>(position.size());
        vector<pair<int, int>> ps;
        ps.reserve(n);

        for(int i = 0; i < n; ++i){
            ps.emplace_back(position[i], speed[i]);
        }   
    
        sort(ps.begin(), ps.end(), 
        [](const auto& a, const auto&b){
            return a.first < b.first;
        });

        stack<pair<int, int>> st;

        for(const auto& car : ps){
            st.push(car);
        }

        double fleet_time = 0.0;
        int ans = 0;

        while(!st.empty()){
            int pos = st.top().first;
            int sp = st.top().second;
            st.pop();

            double current_time = static_cast<double>(target - pos)/sp;

            if(current_time > fleet_time){
                ++ans;
                fleet_time = current_time;
            }

        }

        return ans;
    }
};
