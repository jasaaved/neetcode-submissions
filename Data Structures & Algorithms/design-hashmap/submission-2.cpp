#include <utility>
#include <vector>
using namespace std;

/* The smart / dumb leetcode way
class MyHashMap {
private:
    static constexpr int MaxKeys = 1000001;
    vector<int> my_map;
public:
    MyHashMap() : my_map(MaxKeys, -1) {
        
    }
    
    void put(int key, int value) {
        my_map[key] = value;
    }
    
    int get(int key) {
        return my_map[key];        
    }
    
    void remove(int key) {
        my_map[key] = -1;
    }
};
*/
// The learning way

class MyHashMap {
private:
    static constexpr int BucketCount = 10000;
    vector<vector<pair<int, int>>> MyMap;

    int GetHash(int key){
        return key % BucketCount;
    }

    int GetIndex(int hash, int key){
        for(int i = 0; i < MyMap[hash].size(); ++i){
            if(MyMap[hash][i].first == key){
                return i;
            }
        }

        return -1;
    }

public:
    MyHashMap() : MyMap(BucketCount) {
        
    }
    
    void put(int key, int value) {
        int hash = GetHash(key);
        int index = GetIndex(hash, key);

        if(index != -1){
            MyMap[hash][index].second = value;
        }
        else{
            MyMap[hash].emplace_back(key, value);
        }
    }
    
    int get(int key) {
        int hash = GetHash(key);
        int index = GetIndex(hash, key);
        if(index != -1){
            return MyMap[hash][index].second;
        }
        return -1;   
    }
    
    void remove(int key) {
        int hash = GetHash(key);
        int index = GetIndex(hash, key);

        if(index != -1){
            MyMap[hash][index].first = MyMap[hash].back().first;
            MyMap[hash][index].second = MyMap[hash].back().second;
            MyMap[hash].pop_back();
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */