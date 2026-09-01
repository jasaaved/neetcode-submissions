#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeight = accumulate(weights.begin(), weights.end(), 0);

        int low = *max_element(weights.begin(), weights.end());
        int high = totalWeight;

        while(low < high) {
            int mid = low + (high - low) / 2;
            int total = 0;
            int days_needed = 1;

            for(int weight : weights) {
                if(total + weight > mid) {
                    ++days_needed;
                    total = weight;
                }

                else {
                    total += weight;
                }
            }

            if(days_needed <= days){
                high = mid;
            }

            else{
                low = mid + 1;
            }            
        }

        return high;
    }
};