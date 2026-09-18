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

            bool found_difference = false;

            for (int j = 0; j < smallest; ++j) {
                if (word1[j] != word2[j]) {
                    if (rank[word1[j] - 'a'] > rank[word2[j] - 'a']) {
                        return false;
                    }

                    found_difference = true;
                    break;
                }
            }

            if (!found_difference && word1.size() > word2.size()) {
                return false;
            }
        }

        return true;
    }
};