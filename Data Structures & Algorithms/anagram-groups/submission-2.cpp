#include <array>
#include <unordered_map>
#include <vector>
using namespace std;

struct ArrayHash {
    size_t operator()(const array<int, 26>& arr) const {
        size_t hash = 0;

        for (int num : arr) {
            hash = hash * 31 + num;
        }

        return hash;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int,26>, vector<string>, ArrayHash> mp;

        for(const string& s : strs){
            array<int, 26> count = {0};
            
            for(char c : s){
                ++count[c - 'a'];
            }

            mp[count].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto& [k, v] : mp){
            ans.push_back(v);
        }

        return ans;
    }
};
