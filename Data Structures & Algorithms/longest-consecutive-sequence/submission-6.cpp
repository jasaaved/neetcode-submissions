#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> seq_map;
        int longest = 0;
        
        for (int num : nums){

            auto it = seq_map.find(num - 1);
            if(it != seq_map.end()){
                seq_map[num] = seq_map[num - 1] + 1;
            }
            else{
                seq_map[num] = 1;
            }

            longest = max(longest, seq_map[num]);
            
            int next = num + 1;

            do{
                it = seq_map.find(next);
                if(it != seq_map.end()){
                    seq_map[next] = seq_map[next - 1] + 1;
                    longest = max(seq_map[it->first], longest);
                }
                ++next;
            }while(it != seq_map.end());
            
            
        }   
        
        return longest;
    }
};
