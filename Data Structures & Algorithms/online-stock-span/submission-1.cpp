class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        pair<int, int> p = {price, 1};

        while(!st.empty() && st.top().first <= p.first){
            p.second += st.top().second;
            st.pop();
        }

        st.push(p);
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */