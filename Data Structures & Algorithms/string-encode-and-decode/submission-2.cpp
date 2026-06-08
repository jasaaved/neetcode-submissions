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
            string count = "";
            int j = i;

            while(s[j] != '#'){
                count += s[j]; 
                ++j;
            }

            int num = stoi(count);
            string word = s.substr(j + 1, num);
            decoded.push_back(word);
            i = j + 1 + num;
        }

        return decoded;
    }
};
