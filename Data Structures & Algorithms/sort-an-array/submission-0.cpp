#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        Merge(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void Merge(vector<int>& nums, int left, int right){
        if(left >= right){
            return;
        }

        int mid = left + (right - left) / 2;
        Merge(nums, left, mid);
        Merge(nums, mid + 1, right);


        MergeSort(nums, left, mid, right);
    }

    void MergeSort(vector<int>& nums, int left, int mid, int right){
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

        while(i <= mid){
            temp.push_back(nums[i]);
            ++i;
        }

        while(j <= right){
            temp.push_back(nums[j]);
            ++j;
        }

        for(int i = 0; i < temp.size(); ++i){
            nums[i + left] = temp[i];
        }
    }
};