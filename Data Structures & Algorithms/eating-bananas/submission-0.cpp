#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high) {
            int mid = low + (high - low) / 2;
            int total_hours = 0;

            for(int bananas : piles) {
                total_hours += (bananas + mid - 1) / mid;
            }

            if(total_hours <= h){
                high = mid;
            }

            else{
                low = mid + 1;
            } 
        }
        
        return high;
    }
};
