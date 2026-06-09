#include <vector>
class MyHashSet {
private:
    static constexpr int constraint = 1000001;
    vector<bool> my_set;
public:

    MyHashSet() : my_set(constraint) {
        
    }
    
    void add(int key) {
        my_set[key] = 1;
    }
    
    void remove(int key) {
        my_set[key] = 0;
    }
    
    bool contains(int key) {
        return my_set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */