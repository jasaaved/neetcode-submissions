#include <vector>

class MyHashSet {
public:
    static constexpr int total = 10000;
    vector<vector<int>> buckets;
    
    MyHashSet() : buckets(total) {

    }
    
    void add(int key) {
        if(!contains(key)){
            int hash = key % total;
            buckets[hash].push_back(key);
        }
    }
    
    void remove(int key) {
        int hash = key % total;
        
        for(int i = 0; i < buckets[hash].size(); ++i){
            
            if(buckets[hash][i] == key){
                buckets[hash][i] = buckets[hash].back();
                buckets[hash].pop_back();
                return;
            }

        }
    }
    
    bool contains(int key) {
        int hash = key % total;
        
        for(int i = 0; i < buckets[hash].size(); ++i){ 
            
            if(buckets[hash][i] == key){
                return true;
            }

        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */