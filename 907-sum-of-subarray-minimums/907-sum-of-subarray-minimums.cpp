class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        
        int MOD=1e9+7; 
        int n=nums.size();
        
        long long totalSum=0;
        vector<int>nextSmaller(n),prevSmaller(n);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i])
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
             while(!st.empty() && nums[st.top()]>nums[i])
                st.pop();
            
            if(st.empty())
                nextSmaller[i]=n;
            else
                nextSmaller[i]=st.top();
            
            st.push(i);
        }
        
        
        for(int i=0;i<n;i++){
            long long sum=(long long)(i-prevSmaller[i])*(nextSmaller[i]-i)*nums[i];
            totalSum+=sum;
            totalSum=totalSum%MOD;
        }
        
        
        return totalSum;
    }
};