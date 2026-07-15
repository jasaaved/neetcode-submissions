class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n - 1;
        vector<int> left_sum(n + 1, 0);
        vector<int> right_sum(n + 1, 0);
        
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            left_sum[i +  1] = sum;
        }

        sum = 0;
        for(int i = n - 1; i >= 0; --i){
            sum += nums[i];
            right_sum[i] = sum;
        }
        int i = 1;
        while(i != n + 1){
            if(left_sum[i - 1] == right_sum[i]){
                return i - 1;
            }
            else {
                ++i;
            }
        }

        return -1;
    }
};