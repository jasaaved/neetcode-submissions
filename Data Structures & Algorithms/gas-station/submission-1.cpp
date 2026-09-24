#include <vector>

using namespace std;
class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) const noexcept {
        const int n = static_cast<int>(gas.size());
        int start = 0;
        int current_gas = 0;
        int total_gas = 0;

        for (int i = 0; i < n; ++i) {
            const int difference = gas[i] - cost[i];
            total_gas += difference;
            current_gas += difference;

            if (current_gas < 0) {
                current_gas = 0;
                start = i + 1;
            }
        }
        
        return total_gas >= 0 ? start : -1;
    }
};
