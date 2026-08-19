#include <array>
#include <queue>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> freq{};
        priority_queue<int> pq;

        for(char c : tasks){
            ++freq[c - 'A'];
        }

        for(int each : freq){
            if(each > 0){
                pq.push(each);
            }
        }
        
        int step = 0;
        int cycles = 0;
        vector<int> temp;
  
        while((!pq.empty()) || (!temp.empty())){
            if(!pq.empty()){
                if(pq.top() != 1){
                    temp.push_back(pq.top() - 1);
                }
                
                pq.pop();
            }

            ++cycles;
            ++step;

            if(step > n){
                while(temp.size() > 0){
                    pq.push(temp.back());
                    temp.pop_back();
                }
                step = 0;
            }

        }
        
        return cycles;
    }
};
