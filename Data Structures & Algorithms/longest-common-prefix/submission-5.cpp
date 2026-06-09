#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int common = strs[0].size();

        for(const string& str : strs){
            int i = 0;

            while(i < common && i < str.size() && str[i] == strs[0][i]){
                ++i;
            }

            if(i == 0){
                return "";
            }

            common = i;
        }

        return strs[0].substr(0, common);
    }
};