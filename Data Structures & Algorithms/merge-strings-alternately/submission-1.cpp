#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size1 = 0;
        int size2 = 0;
        string ans;

        while(size1 < static_cast<int>(word1.size()) && size2 < static_cast<int>(word2.size())){
                ans += word1[size1++];
                ans += word2[size2++];
        }

        while(size1 < static_cast<int>(word1.size())){
            ans += word1[size1++];
        }

        while(size2 < static_cast<int>(word2.size())){
            ans += word2[size2++];
        }
        
        return ans;
    }
};