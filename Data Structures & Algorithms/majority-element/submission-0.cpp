class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count = 1;

        for(int num : nums){
            count = (num == majority) ? ++count : --count;

            if(count == 0){
                majority = num;
                count = 1;
            }
        }
        
        return majority;
    }
};