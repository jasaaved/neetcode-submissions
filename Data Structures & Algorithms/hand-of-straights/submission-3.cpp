#include <array>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNStraightHand(const vector<int>& hand, int groupSize) const noexcept  {
        array<int, 1001> counts{};
        const int n = static_cast<int>(hand.size());

        for (int each : hand) {
            ++counts[each];
        }

        for (int card = 0; card <= 1000; ++card) {
            const int count = counts[card];

            if (count == 0) {
                continue;
            }

            counts[card] = 0;

            int current_hand = 1;
            int current_card = card;

            while(current_hand < groupSize) {
                ++current_hand;
                ++current_card;
                
                if(counts[current_card] < count) {
                    return false;
                }

                counts[current_card] -= count;
            }

        }

        return  true;
    }
};
