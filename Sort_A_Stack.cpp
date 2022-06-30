void insertAtSortedStack(stack<int>&st,int val){
    
    if(st.empty() || st.top()<=val)
    {
        st.push(val);
        return;
    }
    
    int topVal=st.top();
    st.pop();
    insertAtSortedStack(st,val);
    st.push(topVal);A
    
}

void sortStack(stack<int> &st)
{
	// Write your code here
    if(st.empty())
        return;
    
    int topVal=st.top();
    st.pop();
    sortStack(st);
    insertAtSortedStack(st,topVal);
}
