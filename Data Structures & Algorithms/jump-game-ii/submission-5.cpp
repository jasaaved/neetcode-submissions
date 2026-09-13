#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(const vector<int>& nums) const noexcept {
        const int n = static_cast<int>(nums.size());

        if (n == 1) {
            return 0;
        }

        int current_jump = nums[0];
        int max_jump = 0;
        int jump = 1;
        for (int i = 0; i < n; ++i) {
            if(current_jump >= n - 1) {
                return jump;
            }

            max_jump = max(max_jump, i + nums[i]);

            if (i == current_jump) {
                current_jump = max_jump;
                ++jump;
            } 
        }

        return jump;
    }
};
