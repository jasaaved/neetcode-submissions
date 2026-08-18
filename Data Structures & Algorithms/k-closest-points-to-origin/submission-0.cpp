#include <cmath>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, CompareDist> pq;

        for(const auto& point : points){
            pq.push(point);

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()){
            vector<int> top = pq.top();
            pq.pop();

            ans.push_back(top);
        }
        
        return ans;
    }

private:
    static float origin_distance(const vector<int>& point){
        return sqrt(point[0]*point[0] + point[1]*point[1]);
    }

    struct CompareDist{
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return (Solution::origin_distance(a) < Solution::origin_distance(b));
        }
    };
};
