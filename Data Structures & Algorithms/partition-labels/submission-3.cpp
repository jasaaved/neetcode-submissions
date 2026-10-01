#include <array>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(const string& s) const 
    {
        array<int, 26> counts{};

        for (char c : s) 
        {
            ++counts[c - 'a'];
        }

        vector<int> partitions;
        int length = 0;
        int count = 0;
        array<bool, 26> seen{};

        for (char c : s) 
        {
            int i = c - 'a';
            ++length;

            if (!seen[i])
            {
                ++count;
                seen[i] = true;
            }

            --counts[i];

            if (counts[i] == 0)
            {
                --count;
            }

            if (count == 0)
            {
                partitions.push_back(length);
                length = 0;
                seen.fill(false);
            }
        }

        return partitions;
    }
};
