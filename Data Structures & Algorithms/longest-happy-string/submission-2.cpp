
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if(a > 0){
            pq.emplace(a, 'a');
        }

        if(b > 0){
            pq.emplace(b, 'b');
        }

        if(c > 0){
            pq.emplace(c, 'c');
        }

        string ans;
        pair<int, char> temp = {0, ' '};

        while(!pq.empty()){
            const int n = static_cast<int>(ans.size());
            auto current = pq.top();
            pq.pop();

            if(n >= 2 && ans[n - 1] == current.second && ans[n - 2] == current.second){
                if(pq.empty()){
                    break;
                }

                auto next = pq.top();
                pq.pop();

                ans += next.second;
                --next.first;

                if(next.first > 0){
                    pq.push(next);
                }

                pq.push(current);
            }
            
            else{
                ans += current.second;
                --current.first;

                if(current.first > 0){
                    pq.push(current);
                }
            }
        }

        return ans;
    }
};