#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> AnagramMap;
        vector<vector<string>> ans;

        for(const string& str : strs){
            int freq[26] = {0};

            for(char c : str){
                ++freq[c - 'a'];
            }

            string key;
            for(int i : freq){
                key += "#";
                key += to_string(i);
            }

            AnagramMap[key].push_back(str);
        }

        for(auto& each : AnagramMap){
            ans.push_back(move(each.second));
        }

        return ans;
    }
};
