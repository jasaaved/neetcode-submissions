#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        freq.reserve(n);

        for(int num : nums){
            ++freq[num];
        }

        vector<vector<int>> buckets(n + 1);

        for(const auto& each : freq){
            buckets[each.second].push_back(each.first);
        }

        vector<int> topK;
        topK.reserve(k);

        for(int i = buckets.size() - 1; i >= 0 && topK.size() < k; --i){
            for(int each : buckets[i]){
                topK.push_back(each);

                if(topK.size() == k){
                    break;
                }
            }
        }

        return topK;
    }
};
