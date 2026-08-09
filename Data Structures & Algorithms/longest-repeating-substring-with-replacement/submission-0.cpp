#include <algorithm>
#include <array>

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = static_cast<int>(s.size());
        int left = 0;
        int ans = 0;
        int most_freq = 0;
        array<int, 26> counts{};

        for(int right = 0; right < n; ++right){
            char c = s[right] - 'A';
            ++counts[c];
            most_freq = max(counts[c], most_freq);

            while(right - left + 1 - most_freq > k){
                --counts[s[left] - 'A'];
                ++left;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
