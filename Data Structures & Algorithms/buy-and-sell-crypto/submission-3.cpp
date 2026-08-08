#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = static_cast<int>(prices.size());
        int cheapest = prices[0];
        int profit = 0;

        for(int i = 1; i < n; ++i){
            cheapest = min(cheapest, prices[i]);
            profit = max(profit, prices[i] - cheapest);
        }

        return profit;
    }
};
