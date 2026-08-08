#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        while(k >= 1){
            
            for(int i = 0; i < n - k; ++i){
                
                if(nums[i] == nums[i + k]){
                    return true;
                }
            }
            --k;
        }
        
        return false;
    }
};