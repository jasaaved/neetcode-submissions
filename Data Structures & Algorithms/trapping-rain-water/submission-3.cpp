#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = static_cast<int>(height.size());
        int leftmost = 0;
        int left = 0;
        int right = n - 1;
        int rightmost = height[right];
        int water = 0;

        while(left < right) {
            leftmost = max(leftmost, height[left]);
            rightmost = max(rightmost, height[right]);

            if(leftmost <= rightmost) {
                water += leftmost - height[left];
                ++left;
            }

            else{
                water += rightmost - height[right];
                --right;
            }
        }
        
        return water;
    }
};
