#include <queue>

using namespace std;

class Solution {
public:
    string predictPartyVictory(const string& senate) {
        queue<int> radiant;
        queue<int> dire;

        const int n = static_cast<int>(senate.size());

        for (int i = 0; i < n; ++i) {
            const char c = senate[i];

            if (c == 'R') {
                radiant.push(i);
            }

            else {
                dire.push(i);
            }
        }


        while (!radiant.empty() && !dire.empty()) {
            if (radiant.front() < dire.front()) {
                dire.pop();
                radiant.push(radiant.front() + n);
                radiant.pop();
            }

            else {
                radiant.pop();
                dire.push(dire.front() + n);
                dire.pop();
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};