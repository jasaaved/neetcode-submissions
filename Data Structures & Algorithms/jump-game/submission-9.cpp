#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(const vector<int>& nums) const noexcept {
        int max_jump = nums[0]; 
        const int n = static_cast<int>(nums.size()) - 1;
        int current = -1;

        while (current != max_jump) {
            ++current;
            max_jump = max(max_jump, nums[current] + current);
            max_jump = clamp(max_jump, 0, n);
        }

        return current < n ? false : true;
    }
};
