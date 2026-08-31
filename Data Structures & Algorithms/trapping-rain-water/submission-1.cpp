#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = static_cast<int>(height.size());
        vector<int> prefix(n);
        vector<int> suffix(n);
        int water = 0;

        prefix[0] = height[0];
        for(int i = 1; i < n; ++i) {
            prefix[i] = max(height[i], prefix[i - 1]);
        }

        suffix[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; --i){
            suffix[i] = max(height[i], suffix[i + 1]);
        }

        for(int i = 0; i < n; ++i){
            water += min(prefix[i], suffix[i]) - height[i];
        }

        return water;
    }
};
