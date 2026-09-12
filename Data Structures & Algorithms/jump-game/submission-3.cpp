class Solution {
public:
    bool canJump(const vector<int>& nums) const noexcept {
        int max_jump = 0; 
        int n = static_cast<int>(nums.size());
        int current = 0;

        while (current < n) {
            max_jump = max(max_jump, nums[current] + current);

            if(current == max_jump && current < n - 1) {
                return false;
            }

            ++current;
        }

        return true;
    }
};
