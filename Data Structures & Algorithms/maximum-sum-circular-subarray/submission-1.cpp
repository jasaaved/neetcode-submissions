#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(const vector<int>& nums) const noexcept {
        const int n = static_cast<int>(nums.size());

        int current_max = nums[0];
        int current_min = nums[0];

        int max_sum = nums[0];
        int min_sum = nums[0];

        int total_sum = nums[0];

        for (int i = 1; i < n; ++i) {
            total_sum += nums[i];

            current_max = max(nums[i], current_max + nums[i]);
            current_min = min(nums[i], current_min + nums[i]);
            
            max_sum = max(max_sum, current_max);
            min_sum = min(min_sum, current_min);
        }

        if (max_sum < 0) {
            return max_sum;
        }
        
        return max(max_sum, total_sum - min_sum);
    }
};