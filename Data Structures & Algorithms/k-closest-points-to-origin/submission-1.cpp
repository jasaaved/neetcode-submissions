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
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }

private:
    static int origin_distance(const vector<int>& point){
        return point[0]*point[0] + point[1]*point[1];
    }

    struct CompareDist{
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return (Solution::origin_distance(a) < Solution::origin_distance(b));
        }
    };
};
