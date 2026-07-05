class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        merge(nums, 0, nums.size() - 1);
        return nums;
    }

private:

    void merge(vector<int>& nums, int left, int right){
        if (left >= right){
            return;
        }

        int mid = (right - left) / 2 + left;
        merge(nums, left, mid);
        merge(nums, mid +  1, right);

        sort(nums, left, right, mid);
    }

    void sort(vector<int>& nums, int left, int right, int mid){
        int i = left;
        int j = mid + 1;

        vector<int> temp;
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

        while(i <= mid){
            temp.push_back(nums[i]);
            ++i;
        }

        while(j <= right){
            temp.push_back(nums[j]);
            ++j;
        }

        for(size_t i = 0; i < temp.size(); ++i){
            nums[i + left] = temp[i];
        }
    } 

};