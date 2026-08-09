#include <string>

using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int n1 = static_cast<int>(s1.size());
        const int n2 = static_cast<int>(s2.size());
        int c_arr[26]{};

        for(char c : s1){
            ++c_arr[c - 'a'];
        }

        int left = 0;
        for(int right = 0; right < n2; ++right){
            int c = s2[right] - 'a';
            --c_arr[c];

            while(c_arr[c] < 0 ){
                int prev_c = s2[left] - 'a';
                ++c_arr[prev_c];
                ++left;
            }

            if(right - left + 1 == n1){
                return true;
            }
        }
        
        return false;
    }
};
