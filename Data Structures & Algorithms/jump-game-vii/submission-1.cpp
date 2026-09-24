#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(const string& s, int minJump, int maxJump) const {
        const int n = static_cast<int>(s.size());
        vector<bool> reachable(n, false);
        reachable[0] = true;
        int count = 0;

        for (int i = minJump; i < n; ++i) {
            const int left = max(0, i - maxJump);
            const int right = i - minJump;

            if (reachable[right] == true) {
                ++count;
            }

            if (left > 0 && reachable[left - 1]) {
                --count;
            }

            if (s[i] == '0' && count > 0) {
                reachable[i] = true;
            }
        }

        return reachable[n - 1];
    }
};