#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();


        for(int i = 0; i < n; ++i){
            int& current = nums[i];
            while(current >= 1 && current <= n && current != nums[current - 1]){
                swap(current, nums[current - 1]);
                current = nums[i];
            }
        }

        for(int i = 0; i < n; ++i){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }

        return n + 1;
    }
};