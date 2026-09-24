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
            const int exiting = i - maxJump - 1;
            const int entering = i - minJump;

            if (reachable[entering] == true) {
                ++count;
            }

            if (exiting >= 0 && reachable[exiting]) {
                --count;
            }
            

            if (s[i] == '0' && count > 0) {
                reachable[i] = true;
            }
        }

        return reachable.back();
    }
};