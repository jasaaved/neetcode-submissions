#include <set>
#include <vector>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sequence;
        int ans = 0;

        for(int num : nums){
            sequence.insert(num);
        }

        for(int each : sequence){
            auto finder = sequence.find(each - 1);
            int count = 0;

            if(finder == sequence.end()){

                do{
                    ++count;
                    finder = sequence.find(each + count);
                } while(finder != sequence.end());

            }

            ans = max(count, ans);
        }
        return ans;
    }
};
