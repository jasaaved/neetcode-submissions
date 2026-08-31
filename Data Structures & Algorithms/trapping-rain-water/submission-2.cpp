#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int right = static_cast<int>(height.size()) - 1;
        int left = 0;
        int leftmax = 0;
        int rightmax = 0;
        int water = 0;

        while(left <= right) {
            leftmax = max(height[left], leftmax);
            rightmax = max(height[right], rightmax);

            if(leftmax <= rightmax) {
                water += leftmax - height[left];
                ++left;
            }

            else {
                water += rightmax - height[right];
                --right;
            }
        }

        return water;
    }
};
