#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int n = static_cast<int>(nums.size());

        for(int right = 1; right < n; ++right){
            
            if(nums[right] > nums[k - 1]){
                nums[k] = nums[right];
                ++k;
            }

        }

        return k;
    }
};