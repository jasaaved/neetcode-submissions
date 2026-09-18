#include <algorithm>
#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAlienSorted(const vector<string>& words, const string& order) const {
        array<int, 26> rank{};

        for (int i = 0; i < 26; ++i) {
            rank[order[i] - 'a'] = i;
        }

        const int n = static_cast<int>(words.size());

        for (int i = 0; i < n - 1; ++i) {
            const string& word1 = words[i];
            const string& word2 = words[i + 1];
            const int smallest = static_cast<int>(
                min(word1.size(), word2.size())
            );


            char c1;
            char c2;
            for (int j = 0; j < smallest; ++j) {
                c1 = word1[j];
                c2 = word2[j];
               
                if (c1 != c2) {
                    if (rank[word1[j] - 'a'] > rank[word2[j] - 'a']) {
                        return false;
                    }

                    break;
                }
            }

            if (c1 == c2 && word1.size() > word2.size()) {
                return false;
            }
        }

        return true;
    }
};