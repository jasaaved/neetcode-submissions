#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int left = 0;
        int sum = 0;
        int ans = n + 1;
        
        for(int right = 0; right < n; ++right){
            sum += nums[right];

            while(sum >= target){            
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }
        
        return (ans > n ? 0 : ans);
    }
};