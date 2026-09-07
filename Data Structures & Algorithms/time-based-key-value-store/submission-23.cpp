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
        mp[key].emplace_back(value, timestamp);
    }
    
    string get(const string& key, int timestamp) {
        auto it = mp.find(key);
        
        if(it == mp.end()) {
            return "";
        }

        const vector<pair<string, int>>& value = it->second;
        int low = 0;
        int high = static_cast<int>(value.size()) - 1;

        while(low < high) {
            int mid = low + (high - low + 1) / 2;

            if(value[mid].second <= timestamp) {
                low = mid;
            }

            else {
                high = mid - 1;
            }
        }
        
        return value[high].second > timestamp ? "" : value[high].first;
    }

private:
    unordered_map<string, vector<pair<string, int>>> mp;
};
