#include <stack>
#include <unordered_map>

using namespace std;

class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        ++freq[val];
        max_freq = max(max_freq, freq[val]);
        freq_stack[freq[val]].push(val);
    }
    
    int pop() {
        int removed = freq_stack[max_freq].top();
        freq_stack[max_freq].pop();

        if(freq_stack[max_freq].empty()) {
            freq_stack.erase(max_freq);
            --max_freq;
        }

        --freq[removed];

        if(freq[removed] == 0) {
            freq.erase(removed);
        }
        
        return removed;
    }

private:
    int max_freq = 0;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> freq_stack;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */