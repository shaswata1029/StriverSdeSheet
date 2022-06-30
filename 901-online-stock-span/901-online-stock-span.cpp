class StockSpanner {
public:
    
    vector<int>prices;
    stack<int>st;
    int curIndex;
    
    StockSpanner() {
        curIndex=-1;
    }
    
    int next(int price) {
        
        prices.push_back(price);
        curIndex++;
        
        int ans=0;
        while(!st.empty() && prices[st.top()]<=price)
            st.pop();
        
        if(st.empty())
            ans=curIndex+1;
        else
            ans=curIndex-st.top();
        
        st.push(curIndex);
        
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */