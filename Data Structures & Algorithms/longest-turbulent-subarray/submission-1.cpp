#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(const vector<int>& arr) const noexcept {
        int n = static_cast<int>(arr.size());
        int left = 0;
        int longest = 1;

        for (int right = 1; right < n; ++right) {
            if (arr[right - 1] == arr[right]) {
                left = right;
            }

            else if (right >= 2) {
                const bool increasing_before = arr[right - 2] < arr[right - 1];
                const bool increasing_now = arr[right - 1] < arr[right];

                left = increasing_before == increasing_now ? right - 1 : left;
            }

            longest = max(longest, right - left + 1);
        }
        
        return longest;
    }
};