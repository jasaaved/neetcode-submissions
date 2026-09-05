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
    
    string get(const string& key, int timestamp) {
        int low = 0;
        int high = static_cast<int>(mp[key].size()) - 1;
        int answer = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if(mp[key][mid].first <= timestamp) {
                answer = mid;
                low = mid + 1;
            }

            else{
                high = mid - 1;
            }
        }

        if(answer == -1) {
            return "";
        }
        
        return mp[key][answer].second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> mp;
};
