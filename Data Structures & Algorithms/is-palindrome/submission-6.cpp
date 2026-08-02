#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while(left < right){

            if(!isalnum(static_cast<unsigned char>(s[left]))){
                ++left;
            }

            else if (!isalnum(static_cast<unsigned char>(s[right]))){
                --right;
            }

            else{ 
                if(tolower(static_cast<unsigned char>(s[left++])) != 
                tolower(static_cast<unsigned char>(s[right--]))){
                    return false;
                }
            }
        }

        return true;
    }
};
