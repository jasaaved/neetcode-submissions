#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        long long max_area = 0;
        int left = 0;
        int right = static_cast<int>(heights.size()) - 1;

        while(left < right){
            long long area = static_cast<long long>(min(heights[left], heights[right])) * (right - left);
            max_area = max(area, max_area);

            if(heights[left] <= heights[right]){
                ++left;
            }

            else{
                --right;
            } 
        }

        return max_area;
    }
};
