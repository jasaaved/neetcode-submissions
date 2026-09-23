
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<vector<int>, vector<vector<int>>, Comparer> pq;

        sort(trips.begin(), trips.end(), 
            [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; 
        });

        int passengers = 0;
        for(const auto& trip : trips) {
            while (!pq.empty() && trip[1] >= pq.top()[2]) {
                passengers -= pq.top()[0];
                pq.pop();
            }
                    
            passengers += trip[0];

            if(passengers > capacity) {
                return false;
            }
            
            pq.push(trip);
        }

        return true;
    }

private:
    struct Comparer {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return a[2] > b[2];
        }
    };
};