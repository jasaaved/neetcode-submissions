#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;

        for(int num : nums){
            ++freqs[num];
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for(auto freq : freqs){
            buckets[freq.second].push_back(freq.first);
        }

        vector<int> topK;

        for(int i = buckets.size() - 1; i >= 0 && topK.size() < k; --i){
            for(int j : buckets[i]){
                topK.push_back(j);
                
                if(topK.size() == k){
                    break;
                }
            }
        }
        
        return topK;
    }
};
