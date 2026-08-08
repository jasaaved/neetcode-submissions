#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        unordered_set<int> st;
        st.reserve(k);

        for(int j = 0; j < n; ++j){
            
            if(!st.insert(nums[j]).second){
                return true;
            }

            if(st.size() > static_cast<size_t>(k)){
                st.erase(nums[j - k]);
            }
        }
                    
        return false;
    }
};