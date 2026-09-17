#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(const vector<int>& nums) const noexcept {
        int max_jump = 0; 
        const int n = static_cast<int>(nums.size());
        
        for (int i = 0; i < n; ++i) {
            if(i > max_jump) {
                return false;
            }

            max_jump = max(max_jump, nums[i] + i);

            if (max_jump >= n - 1) {
                return true;
            }

        }

        return true;
    }
};
