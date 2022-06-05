class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();
        
        int start=0;
        int end=0;
        
        int max_len=0;
        
        map<char,int>hashMap;
        
        while(end<n){
            char ch=s[end];
            
            if(hashMap.find(ch)!=hashMap.end())
                start=max(start,hashMap[ch]+1);
            
            max_len=max(max_len,end-start+1);
            hashMap[ch]=end;
                
            end++;
        }
        
        return max_len;
        
    }
};