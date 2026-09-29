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
        string partition;
        int count = 0;
        array<int, 26> current_count{};

        for (char c : s) 
        {
            int i = c - 'a';
            partition += c;

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
                partitions.push_back(partition.size());
                current_count.fill(0);
                partition = "";
            }
        }

        return partitions;
    }
};
