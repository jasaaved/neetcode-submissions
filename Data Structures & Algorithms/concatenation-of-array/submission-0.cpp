class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans = nums;
        ans.reserve(2*n);

        for(int i = 0; i < n; ++i){
            ans.push_back(ans[i]);
        }
        
        return ans;
    }
};