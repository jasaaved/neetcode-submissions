#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;

        int prefix = 0;
        for(int num : nums){
            prefix += num;
            ans += mp[prefix - k];
            ++mp[prefix];
        }

       return ans; 
    }
};