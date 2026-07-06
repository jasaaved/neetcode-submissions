#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums){
            ++mp[num];
        }
        
        vector<vector<int>> buckets(nums.size() + 1);        
        for(const auto& [num, freq] : mp){
            buckets[freq].push_back(num);
        }

        vector<int> ans;
        for(int i = buckets.size() - 1; i >= 0 && ans.size() != k; --i){
            
            for(int num : buckets[i]){
                ans.push_back(num);
                
                if(ans.size() == k){
                    break;
                }
            }
        }

        return ans;
    }
};
