#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        const int n = static_cast<int>(tasks.size());
        
        for(int i = 0; i < n; ++i){
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>&b){
            return a[0] > b[0];
        });

        int time = 0;
        vector<int> ans;
        ans.reserve(n);

        while(!pq.empty() || !tasks.empty()){
            while(!tasks.empty() && tasks.back()[0] <= time){
                pq.push(tasks.back());
                tasks.pop_back();
            }

            if(!pq.empty()){
                time += pq.top()[1];
                ans.push_back(pq.top()[2]);
                pq.pop();
            }

            else{
                ++time;
            }
        }
        
        return ans;
    }

private:
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            if(a[1] == b[1]){
                return a[2] > b[2];
            }

            return a[1] > b[1];
        }
    };

    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
};