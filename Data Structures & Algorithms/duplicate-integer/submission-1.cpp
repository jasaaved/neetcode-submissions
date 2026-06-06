#include <unordered_set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for(int i = 0; i < nums.size(); ++i){

            if(set.count(nums[i])){
                return true;
            }
            
            set.insert(nums[i]);
        }
        
        return false;
    }
};