#include <algorithm>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest_area = 0;
        stack<pair<int, int>> st;
        heights.push_back(0);
        const int n = static_cast<int>(heights.size());
        

        for(int i = 0; i < n; ++i) {
            int start = i;

            while(!st.empty() && heights[i] < st.top().second){
                pair<int, int> top = st.top();
                st.pop();

                int current_area = top.second * (i - top.first);
                largest_area = max(current_area, largest_area);
                start = top.first;
            }

            st.emplace(start, heights[i]);
        }

        return largest_area;
    }
};
