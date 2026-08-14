#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st2.empty()){
            st1.push(x);
        }

        else{
            transfer(st2, st1);
            st1.push(x);
        } 
    }
    
    int pop() {
        if(!st1.empty()){
            transfer(st1, st2);
        }
        int front = st2.top();
        st2.pop();
        return front;
    }
    
    int peek() {
        if(!st1.empty()){
            transfer(st1, st2);
        }

        return st2.top();
    }
    
    bool empty() {
        return (st1.empty() && st2.empty());
    }

private:
    stack<int> st1;
    stack<int> st2;

    void transfer(stack<int>& from, stack<int>& to){
        while(!from.empty()){
            to.push(from.top());
            from.pop();
        }
    }


};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */