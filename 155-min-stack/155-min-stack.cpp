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
//             If val is greater than the minimum no need to update the minimum
            st.push(val*1LL);
        else{
//             Update the minimum to val and push into the stack the modified val such that it is always lesser than the minimum
            long long newVal=2LL*val-minVal;
            st.push(newVal);
            minVal=val;
        }
        
    }
    
    void pop() {
//         If the top is lesser than the minimum then we need to revert back to the previous minimum after popping from the stack using the formula 
        if(st.top()<minVal)
        {
            long long val=st.top();
            minVal=2LL*minVal-val;
           
        }
         st.pop();
    }
    
    int top() {
//         If the top is lesser than the minimum then the top has modified val and the top element is the min value only
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