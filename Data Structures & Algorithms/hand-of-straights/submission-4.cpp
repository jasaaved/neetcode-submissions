#include <array>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNStraightHand(const vector<int>& hand, int groupSize) const noexcept  {
        const int n = static_cast<int>(hand.size());

        if (n % groupSize != 0) {
            return false;
        }

        array<int, 1001> counts{};
        
        for (int each : hand) {
            ++counts[each];
        }

        for (int card = 0; card <= 1000 - groupSize + 1; ++card) {
            const int count = counts[card];

            if (count == 0) {
                continue;
            }

            for (int offset = 0; offset < groupSize; ++offset) {
                if (counts[card + offset] < count) {
                    return false;
                }

                counts[card + offset] -= count;
            }

        }

        return  true;
    }
};
