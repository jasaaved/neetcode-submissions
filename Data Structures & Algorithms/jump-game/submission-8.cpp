#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(const vector<int>& nums) const noexcept {
        int max_jump = nums[0]; 
        int n = static_cast<int>(nums.size());
        int current = -1;

        while (current != max_jump) {
            ++current;
            max_jump = min(max(max_jump, nums[current] + current), n - 1);
        }

        return current < n - 1 ? false : true;
    }
};
