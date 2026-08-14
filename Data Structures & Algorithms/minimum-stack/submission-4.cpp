class MinStack {
public:
    MinStack() {
        minimum = INT_MAX;  
    }
    
    void push(int val) {
        if(val < minimum){
            minimum = val;
        }

        min_stack.push(minimum);
        st.push(val);
    }
    
    void pop() {
        min_stack.pop();
        st.pop();

        if(min_stack.empty()){
            minimum = INT_MAX;
        }
        else{
            minimum = min_stack.top();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_stack.top();    
    }
private:
    int minimum;
    stack<int> min_stack;
    stack<int> st;

};
