#include <set>
#include <vector>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> sequence;
        int ans = 0;

        for(int num : nums){
            sequence.insert(num);
        }

        for(int each : sequence){
            auto finder = sequence.find(each - 1);
            int count = 0;

            if(finder == sequence.end()){
                ++count;
                auto finder = sequence.find(each + 1);
                while(finder != sequence.end()){
                    ++count;
                    finder = sequence.find(each + count);
                }
            }

            ans = max(count, ans);
            
        }
        return ans;
    }
};
