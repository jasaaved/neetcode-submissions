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
        array<int, 26> current_count{};

        for (char c : s) 
        {
            int i = c - 'a';
            ++length;

            if (current_count[i] == 0)
            {
                ++count;
            }

            ++current_count[i];
            --counts[i];

            if (counts[i] == 0)
            {
                --count;
            }

            if (count == 0)
            {
                partitions.push_back(length);
                length = 0;
                current_count.fill(0);
            }
        }

        return partitions;
    }
};
