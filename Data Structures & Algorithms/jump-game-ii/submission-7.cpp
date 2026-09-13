#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(const vector<int>& nums) const noexcept {
        const int n = static_cast<int>(nums.size());
        int current_jump = 0;
        int farthest_jump = 0;
        int jump = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest_jump = max(farthest_jump, i + nums[i]);

            if (i == current_jump) {
                current_jump = farthest_jump;
                ++jump;
            } 
        }

        return jump;
    }
};
