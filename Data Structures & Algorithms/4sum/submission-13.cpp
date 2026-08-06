#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        int left1 = 0;
        int right1 = n - 1;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int l1 = 0; l1 < n - 1; ++l1){
            if(l1 != 0 && nums[l1] == nums[l1 - 1]){
                continue;
            }

            for(int r1 = n - 1; r1 > l1; --r1){
                if(r1 != n - 1 && nums[r1] == nums[r1 + 1]){
                    continue;
                }

                int l2 = l1 + 1;
                int r2 = r1 - 1;

                while(l2 < r2){
                    long long sum = static_cast<long long>(nums[l1]) + nums[l2] + nums[r2] + nums[r1];
                    if(sum < target){
                        ++l2;
                    }

                    else if(sum > target){
                        --r2;
                    }

                    else{
                        ans.push_back({nums[l1], nums[l2], nums[r2], nums[r1]});
                        ++l2;
                        --r2;

                        while(l2 < r2 && nums[l2 - 1] == nums[l2]){
                            ++l2;
                        }

                        while(l2 < r2 && nums[r2 + 1] == nums[r2]){
                            --r2;
                        }
                    }
                }
            }
        }

        return ans;
    }

};