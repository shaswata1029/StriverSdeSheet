class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n=num.size();
        
        int count=0;
        
        stack<int>st;
        
        for(int index=0;index<n;index++)
        {
            int digit=num[index]-'0';
            while(!st.empty() && count<k && st.top()>digit){
                 st.pop();
                count++;
            }
               
            
            st.push(digit);
        }
        
        while(!st.empty() && count<k){
            st.pop();
            count++;
        }
            
        
        
        
        string res="";
        while(!st.empty()){
            res.push_back(st.top()+'0');
            st.pop();
        }
        
        while(res.size()>0 && res.back()=='0')
            res.pop_back();
        
        if(res.size()==0)
            res="0";
        
        reverse(res.begin(),res.end());
        return res;
            
        
    }
};