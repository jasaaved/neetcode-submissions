#include <string>
#include <vector>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];

        for(const string& str : strs){
            int n = str.size();

            if(n == 0){
                return "";
            }

            common = common.substr(0, n);
            for(int i = 0; i < n; ++i){
                if(str[i] != common[i]){
                    common = common.substr(0, i);
                    break;
                }
            }
        }

        return common;
    }
};