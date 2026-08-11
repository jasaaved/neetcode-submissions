class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = nums[0];

        for(int num : nums){
            if(sum < 0){
                sum = 0;
            }
            sum += num;
            max_sum = max(max_sum, sum);
        }

        return max_sum;
    }
};
