class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int best = nums[0];

        for(int num : nums){
            int c = sum + num;
            best = max(best, c);

            if(c < 0){
                sum = 0;
            }
            else{
                sum = c;
            }
        }

        return best;
    }
};
