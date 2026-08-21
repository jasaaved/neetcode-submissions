class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid = 0;
        int left = 0;
        int right = static_cast<int>(nums.size());

        while(left < right){
            mid = ((right - left) / 2) + left;

            if(target <= nums[mid]){
                right = mid;
            }

            else{
                left = mid + 1;
            }
        }

        return left;
    }
};