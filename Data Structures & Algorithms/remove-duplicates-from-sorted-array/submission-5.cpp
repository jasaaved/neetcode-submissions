#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int right = 0;
        int k = 0;

        while(right < static_cast<int>(nums.size())){
            
            while(right < static_cast<int>(nums.size()) && nums[k] >= nums[right]){
                ++right;
            }

            if(right < static_cast<int>(nums.size()))
                swap(nums[k + 1], nums[right]);
            ++k;
        }
        
        return k;
    }
};