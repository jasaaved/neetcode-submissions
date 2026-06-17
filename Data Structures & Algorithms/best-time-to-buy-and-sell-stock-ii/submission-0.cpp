#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int prev = -1;
        for(int price : prices){
            if (prev != -1 && price > prev){
                profit += price - prev;
            }
            prev = price;
        }

        return profit;        
    }
};