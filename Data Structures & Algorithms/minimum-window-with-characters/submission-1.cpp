#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;

        for(char c : t) {
            ++need[c];
        }

        const int n1 = static_cast<int>(need.size());
        int required = 0;

        const int n2 = static_cast<int>(s.size());
        int smallest = n2 + 1;
        unordered_map<char, int> window;
        int left = 0;
        int start = left;

        for(int right = 0; right < n2; ++right) {
            char c = s[right];
            
            ++window[c];

            if(need.count(c) && window[c] == need[c]) {
                ++required;
            }

            while(required == n1) {
                char left_char = s[left];
                int length = right - left + 1;
                
                if(length < smallest) {
                    start = left;
                    smallest = length;
                }

                if(need.count(left_char) && window[left_char] == need[left_char]) {
                    --required;
                }

                --window[left_char];
                ++left;
            }
        }
        
    
        return smallest == n2 + 1 ? "" : s.substr(start, smallest);
    }
};
