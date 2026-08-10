#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();
        int left = 0;
        int sum = 0;
        int ans = 0;
        
        for(int right = 0; right < n; ++right){
            sum += nums[right];

            while(sum >= target){
                if(ans == 0){
                    ans = (right - left + 1);
                }

                else{
                    ans = min(ans, right - left + 1);
                }

                sum -= nums[left];
                ++left;
            }
        }
        
        return ans;
    }
};