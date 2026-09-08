#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(const vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0); 
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            int current_sum = 0;
            int subarrays = 1;

            for(int num : nums) {
                current_sum += num;

                if(current_sum > mid) {
                    ++subarrays;
                    current_sum = num; 
                }
            }

            if(subarrays <= k) {
                high = mid;
            }

            else {
                low = mid + 1;
            }
        }
        
        return high;
    }
};