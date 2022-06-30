class Solution {
public:
    bool isValid(string str) {
        
        int n=str.size();
        
        if(n%2==1)
            return false;
        
        stack<int>st;
        
        for(int i=0;i<n;i++){
            char ch=str[i];
            
            if(ch=='(' || ch=='[' || ch=='{')
                st.push(ch);
            else if(ch==')'){
                if(st.empty() || st.top()!='(')
                    return false;
                st.pop();
            }else if(ch==']'){
                 if(st.empty() || st.top()!='[')
                    return false;
                st.pop();
            }else if(ch=='}'){
                if(st.empty() || st.top()!='{')
                    return false;
                st.pop();
            }
        }
        
        if(st.empty())
        return true;
        
        return false;
    }
};