#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& nums, const int k) const {
        priority_queue<pair<int, int>> pq;
        const int n = static_cast<int>(nums.size());
        vector<int> ans;
        ans.reserve(n - k + 1);
        int left = 0;

        for(int right = 0; right < n; ++right) {
            int length = right - left + 1;
            pq.emplace(nums[right], right);

            if(length == k) {
                ans.push_back(pq.top().first);

                while(!pq.empty() && pq.top().second <= left){
                    pq.pop();
                }

                ++left;
            }
        }
        
        return ans;
    }
};
