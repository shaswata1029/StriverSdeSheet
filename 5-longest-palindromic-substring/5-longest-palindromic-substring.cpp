class Solution {
public:
    int findLongestSubstring(string &str,int n,int start,int end){
        
        while(start>=0 && end<n && str[start]==str[end]){
            start--;
            end++;
        }
        
        return (end-start-1);
    }
    
    string longestPalindrome(string s) {
        
        int n=s.size();
        int start=0,maxLen=1;
        
        for(int k=0;k<n;k++){
            int len=findLongestSubstring(s,n,k,k);
            len=max(len,findLongestSubstring(s,n,k,k+1));
            
            if(len>maxLen){
                maxLen=len;
                start=k-(len-1)/2;
            }
        }
        
         
        
        
        string res=s.substr(start,maxLen);
        return res;
    
    }
};