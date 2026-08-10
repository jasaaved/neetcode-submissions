class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int n = static_cast<int>(arr.size());
        vector<int> ans;
        ans.reserve(k);
        int left = 0;
        for(int right = 0; right < n; ++right){
            while(right - left + 1 > k && abs(arr[left] - x) > abs(arr[right] - x)){
                    ++left;
            }
        }

        for(int i = left; ans.size() < k; ++i){
            ans.push_back(arr[i]);
        }

        return ans;
    }

    
};