#include <list>
#include <unordered_map>
#include <utility>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        size = 0;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        
        if(it != cache.end()){
            lru.splice(lru.begin(), lru, it->second);
            return it->second->second;
        }

        return -1;
    }
    
    void put(int key, int value) {        
        auto it = cache.find(key);

        if(it != cache.end()){
            it->second->second = value;
            lru.splice(lru.begin(), lru, it->second);
            return;
        }

        lru.emplace_front(key, value);
        cache[key] = lru.begin();
        ++size;
        
        if(size > capacity){
            cache.erase(lru.back().first);
            lru.pop_back();
            --size;
        }
        
        return;
    }

private:
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int capacity;
    int size;
};
