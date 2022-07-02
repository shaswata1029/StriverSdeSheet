#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> v, int n) {
    // Write your code here.
    vector<int>nextSmaller(n),prevSmaller(n);
    
    stack<int>st;
    
    for(int i=0;i<n;i++){
        while(!st.empty() && v[st.top()]>=v[i])
            st.pop();
        
        if(st.empty())
            prevSmaller[i]=-1;
        else
            prevSmaller[i]=st.top();
        st.push(i);
    }
    
    
    while(!st.empty())
        st.pop();
    
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && v[st.top()]>=v[i])
            st.pop();
        
        if(st.empty())
            nextSmaller[i]=n;
        else
            nextSmaller[i]=st.top();
        st.push(i);
    }
    
    vector<int>res(n,INT_MIN);
    
    for(int i=0;i<n;i++){
        int width=nextSmaller[i]-prevSmaller[i]-1;
        res[width-1]=max(res[width-1],v[i]);
    }
    
    
    for(int i=n-2;i>=0;i--)
        res[i]=max(res[i],res[i+1]);
    
    return res;
    
    
    
    
}
