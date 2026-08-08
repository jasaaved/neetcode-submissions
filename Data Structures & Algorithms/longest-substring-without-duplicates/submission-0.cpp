#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = static_cast<int>(s.size());
        unordered_set<char> char_set;
        int left = 0;
        int ans = 0;
        
        for(int right = 0; right < n; ++right){

            while(!char_set.insert(s[right]).second){
                char_set.erase(s[left]);
                ++left;
            }

            ans = max(ans, static_cast<int>(char_set.size()));
        }

        return ans;
    }
};
