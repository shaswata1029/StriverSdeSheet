class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        
        map<int,int>hashMap;
        for(int i=0;i<m;i++)
            hashMap[nums2[i]]=i;
        
        vector<int>res(n);
        stack<int>st;
        
        vector<int>next(m);
        for(int i=m-1;i>=0;i--){
            int number=nums2[i];
            
            while(!st.empty() && st.top()<number)
                st.pop();
            
            if(st.empty())
                next[i]=-1;
            else
                next[i]=st.top();
            
            st.push(number);
        }
        
       for(int i=0;i<n;i++){
           res[i]=next[hashMap[nums1[i]]];
       }
        
        return res;
        
    }
};