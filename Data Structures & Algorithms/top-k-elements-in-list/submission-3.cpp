#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int num : nums){
            ++mp[num];
        }

        unordered_map<int, vector<int>> count;
        int highest = 0;
        for(auto [k, v] : mp){
            count[v].push_back(k);
            highest = max(highest, v);
        }

        vector<int> ans;
        ans.reserve(k);
        while(ans.size() != k){

            for(int i = 0; i < count[highest].size(); ++i){
                ans.push_back(count[highest][i]);
                if (ans.size() == k){
                    break;
                }
            }
            --highest;
        }

        return ans;
    }
};
