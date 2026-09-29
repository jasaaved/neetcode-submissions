#include <algorithm>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
    bool mergeTriplets(const vector<vector<int>>& triplets, const vector<int>& target) const 
    {
        array<int, 3> current{};

        for (const vector<int>& triplet : triplets) 
        {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) 
            {
                continue;
            }

            for (int i = 0; i < 3; ++i) 
            {
                current[i] = max(current[i], triplet[i]);
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            if (current[i] != target[i]) 
            {
                return false;
            }
        }
        
        return true;
    }
};
