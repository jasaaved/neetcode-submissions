#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while(left < right){
            
            if(s[left] != s[right]){
                return (validPalindrome(s, left + 1, right) || 
                validPalindrome(s, left, right - 1));
            }

            else{
                ++left;
                --right;
            }
        }
        
        return true;
    }

private:
    bool validPalindrome(const string& s, int left, int right){

        while(left < right){
            
            if(s[left++] != s[right--]){
                return false;
            }
        }

        return true;
    }
};