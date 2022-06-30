void insertAtBottom(stack<int>& st,int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    
    int topVal=st.top();
    st.pop();
    insertAtBottom(st,val);
    st.push(topVal);
}

void reverseStack(stack<int> &st) {
    // Write your code here
    if(st.empty())
        return;
    
    int topVal=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,topVal);
    
}
