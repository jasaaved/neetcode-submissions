#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq_set(nums.begin(), nums.end());
        int longest = 0;
        
        for (int num : seq_set){
            auto it = seq_set.find(num - 1);

            if(it == seq_set.end()){
                int current_seq = 1;

                while(seq_set.find(++num) != seq_set.end()){
                    ++current_seq;
                }

                longest = max(current_seq, longest);
            }
        }   
        
        return longest;
    }
};
