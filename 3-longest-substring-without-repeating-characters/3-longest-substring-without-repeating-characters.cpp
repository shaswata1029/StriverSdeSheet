class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();
        
        int start=0;
        int end=0;
        
        int max_len=0;
        
        map<char,int>lastSeen;
        
        while(end<n){
            char ch=s[end];
            
            if(lastSeen.find(ch)!=lastSeen.end())
                start=max(start,lastSeen[ch]+1);
            
            max_len=max(max_len,end-start+1);
            lastSeen[ch]=end;
                
            end++;
        }
        
        return max_len;
        
    }
};