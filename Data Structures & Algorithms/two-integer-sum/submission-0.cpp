#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;

        for(size_t i = 0; i < nums.size(); ++i){
            int j = target - nums[i];
            auto it = mp.find(j);
            
            if(it == mp.end()){
                mp[nums[i]] = i;
            }
            else{
                ans.push_back(it->second);
                ans.push_back(i);
                
                break;
            }

        }

        return ans;
    }
};
