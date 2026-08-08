#include <algorithm>
#include <array>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = static_cast<int>(s.size());
        array<int, 256> c_arr;
        c_arr.fill(-1);
        int ans = 0;
        int left = 0;

        for(int right = 0; right < n; ++right){
            unsigned char c = static_cast<unsigned char>(s[right]);
            left = max(left, c_arr[c] + 1);
            c_arr[c] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
