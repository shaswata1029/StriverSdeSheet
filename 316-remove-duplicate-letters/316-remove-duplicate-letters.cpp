class Solution {
public:
    string removeDuplicateLetters(string str) {
        
        int n=str.size();
        
        vector<int>totalFreq(26,0);
        vector<int>freq(26,0);
        
        for(int i=0;i<n;i++)
            totalFreq[str[i]-'a']++;
        
        stack<char>st;
        
        for(int i=0;i<n;i++){
            char ch=str[i];
            
            if(freq[ch-'a']>0){
                totalFreq[ch-'a']--;
                continue;
            }
                
            
            while(!st.empty() && st.top()>ch && totalFreq[st.top()-'a']>0){
                freq[st.top()-'a']--;
                st.pop();
            }
            
            st.push(ch);
            totalFreq[ch-'a']--;
            freq[ch-'a']++;
            
        }
        
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
        
    }
};