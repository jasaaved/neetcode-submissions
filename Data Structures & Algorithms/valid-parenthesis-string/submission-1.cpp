#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(const string& s) 
    {
        stack<char> st;
        int maxopen = 0;
        int minopen = 0;

        for (char c : s) 
        {
            if (c == '(') 
            {
                ++maxopen;
                ++minopen;
            }

            else 
            {
                minopen = max(0, minopen - 1);

                if (c == ')') 
                {
                    --maxopen;
                }

                else 
                {
                    ++maxopen;
                }
            }

            if(maxopen < 0) {
                return false;
            }
        }
        
        return minopen == 0 ? true : false;
    }
};
