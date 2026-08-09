class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int n1 = static_cast<int>(s1.size());
        const int n2 = static_cast<int>(s2.size());
        int c1[26]{};
        int c2[26]{};

        for(int i = 0; i < n1; ++i){
            ++c1[s1[i] - 'a'];
        }

        int left = 0;
        for(int right = 0; right < n2; ++right){
            int c = s2[right] - 'a';
            ++c2[c];

            if(c1[c] == c2[c]){
                if(right - left + 1 == n1){
                    return true;
                }
            }

            while(c2[c] > c1[c]){
                int prev_c = s2[left] - 'a';
                --c2[prev_c];
                ++left;
            }
        }
        
        return false;
    }
};
