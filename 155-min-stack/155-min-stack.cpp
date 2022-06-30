class MinStack {
public:
    stack<long long>st;
    long long minVal;
    
    MinStack() {
        minVal=INT_MAX;
    }
    
    void push(int val) {
        
        if(st.empty()){
            st.push(val*1LL);
            minVal=val;
        }else if(val>=minVal)
            st.push(val*1LL);
        else{
            long long newVal=2LL*val-minVal;
            st.push(newVal);
            minVal=val;
        }
        
    }
    
    void pop() {
        if(st.top()<minVal)
        {
            long long val=st.top();
            minVal=2LL*minVal-val;
           
        }
         st.pop();
    }
    
    int top() {
        if(st.top()<minVal)
            return minVal;
        
        return st.top();
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */