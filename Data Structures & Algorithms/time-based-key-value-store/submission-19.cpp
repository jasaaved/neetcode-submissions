#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(const string& key, const string& value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key) == 0) {
            return "";
        }

        int low = 0;
        int high = static_cast<int>(mp[key].size()) - 1;

        while(low < high) {
            int mid = low + (high - low + 1) / 2;

            if(mp[key][mid].first <= timestamp) {
                low = mid;
            }

            else {
                high = mid - 1;
            }
        }

        const pair<int, string>& value = mp[key][high];
        return value.first > timestamp ? "" : value.second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> mp;
};
