#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, k, n - 1);
        reverse(nums, 0, k - 1);
    }
private:
    void reverse(vector<int>& nums, int left, int right){
        while(left < right){
            swap(nums[left], nums[right]);
            ++left;
            --right;
        }
    }
};