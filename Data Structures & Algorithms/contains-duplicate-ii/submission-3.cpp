#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        unordered_set<int> st;
        st.reserve(k);

        int i = 0;
        for(int j = 0; j < n; ++j){
            
            if(!st.insert(nums[j]).second){
                return true;
            }

            if(st.size() > k){
                st.erase(nums[i]);
                ++i;
            }
        }
                    
        return false;
    }
};