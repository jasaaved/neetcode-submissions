class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<vector<int>, vector<vector<int>>, Comparer> pq;
        sort(trips.begin(), trips.end(), 
        [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1]; 
        });

        int current_cap = 0;
        for(const auto& trip : trips){
            while (!pq.empty() && trip[1] >= pq.top()[2]){
                current_cap -= pq.top()[0];
                pq.pop();
            }
                    
            current_cap += trip[0];

            if(current_cap > capacity){
                return false;
            }
            
            pq.push(trip);
        }

        return true;
    }

private:
    struct Comparer{
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return a[2] > b[2];
        }
    };
};