#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        
        for(const string& str : strs){
            encoded += to_string(str.size());
            encoded += '#';
            encoded += str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i = 0;
        while(i < s.size()){
            int count = 0;

            while(s[i] != '#'){
                count = count * 10 + (s[i] - '0'); 
                ++i;
            }

            ++i;
            decoded.push_back(s.substr(i, count));
            i += count;
        }

        return decoded;
    }
};
