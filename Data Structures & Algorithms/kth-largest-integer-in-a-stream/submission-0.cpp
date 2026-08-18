#include <queue>

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;

        for(int num : nums){
            add(num);
        }
        
    }
    
    int add(int val) {{
        pq.push(val);

        if(pq.size() > size){
            pq.pop();
        }

        return pq.top();
    }
        
    }
private:
    int size; 
    priority_queue<int, vector<int>, greater<int>> pq;
};
