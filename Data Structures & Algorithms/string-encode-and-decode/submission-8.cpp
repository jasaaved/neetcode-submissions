class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;

        for(const string& str : strs){
            encoded += to_string(str.size());
            encoded += "#";
            encoded += str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        string word;
        int size = -1;
        for(char c : s){
            if (size < 0 && c != '#'){
                word += c;
            }
            else if(size < 0 && c == '#'){
                size = stoi(word);
                word = "";
            }
            else{
                word += c;
            }

            if(word.size() == size){
                decoded.push_back(word);
                size = -1;
                word = "";
            }
        }

        return decoded;
    }
};
