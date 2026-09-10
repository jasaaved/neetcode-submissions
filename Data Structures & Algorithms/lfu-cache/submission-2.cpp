#include <list>
#include <unordered_map>
#include <utility>

class LFUCache {
public:
    LFUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        CacheIterator it = cache.find(key);

        if(it == cache.end()){
            return -1;
        }

        update_pos(it);

        return it->second.second->second;
    }
    
    void put(int key, int value) {
        CacheIterator it = cache.find(key);

        if(it == cache.end()){
            if(size == capacity){
                int old_key = freq[minfreq].back().first;
                freq[minfreq].pop_back();
                cache.erase(old_key);
                --size;
            }
            
            minfreq = 1;
            freq[minfreq].emplace_front(key, value);

            cache[key] = {minfreq, freq[minfreq].begin()};
            ++size;
        }
        else{
            update_pos(it);
            it->second.second->second = value;
        }

    }

private:
    using NodeIterator = list<pair<int, int>>::iterator;
    using CacheIterator = unordered_map<int, pair<int, NodeIterator>>::iterator;
    unordered_map<int, pair<int, NodeIterator>> cache;
    unordered_map<int, list<pair<int, int>>> freq;
    int size = 0;
    int minfreq = 0;
    int capacity;

    void update_pos(CacheIterator it) {
        int current_freq = it->second.first;

        freq[current_freq + 1].splice(freq[current_freq + 1].begin(), freq[current_freq], it->second.second);

        ++it->second.first;
        if(current_freq == minfreq && freq[current_freq].empty()) {
            ++minfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */