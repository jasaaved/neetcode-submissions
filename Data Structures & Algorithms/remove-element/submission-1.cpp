#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; ++i){

            if(nums[i] != val){
                nums[ans++] = nums[i];
            
            }
        }
        
        return ans;
    }
};