#include <algorithm>
#include <vector>
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0;
        int right = static_cast<int>(people.size()) - 1;
        int ans = 0;
        
        while(left <= right){
            
            if(people[right] == limit || people[left] + people[right] > limit){
                ++ans;
                --right;
            }

            else{
                ++left;
                --right;
                ++ans;
            }
        }
        
        return ans;
    }
};