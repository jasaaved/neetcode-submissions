#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool mergeTriplets(const vector<vector<int>>& triplets, const vector<int>& target) {
        vector<int> current(3, 0);

        for (const vector<int>& triplet : triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
                continue;
            }

            current[0] = max(current[0], triplet[0]);
            current[1] = max(current[1], triplet[1]);
            current[2] = max(current[2], triplet[2]);
        }

        const int n = static_cast<int>(target.size());

        for (int i = 0; i < n; ++i) {
            if (current[i] != target[i]) {
                return false;
            }
        }
        
        return true;
    }
};
