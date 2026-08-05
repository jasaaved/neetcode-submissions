#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = static_cast<int>(numbers.size()) - 1;
        int sum = numbers[left] + numbers[right];

        while(left < right){
            if(sum == target){
                return {left + 1, right + 1};
            }

            else if(sum > target){
                --right;
            }

            else{
                ++left;
            }
            
            sum = numbers[left] + numbers[right];
        }
        
        return {};
    }
};
