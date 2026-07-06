class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        split(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void split(vector<int>& nums, int left, int right){
        if  (left >= right){
            return;
        }

        int mid = (right - left) / 2 + left;
        split(nums, left, mid);
        split(nums, mid +  1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> temp;
        int i = left;
        int j = mid + 1;

        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                ++i;
            }
            else{
                temp.push_back(nums[j]);
                ++j;
            }
        }

        int k = (i <= mid) ? i : j;
        int stop = (k == i) ? mid : right;
        
        while(k <= stop){
            temp.push_back(nums[k]);
            ++k;
        }

        size_t n = temp.size();
        for(size_t i = 0; i < n; ++i){
            nums[i + left] = temp[i];
        }
    }
};