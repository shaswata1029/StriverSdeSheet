class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        
        int n=strs.size();
        if(n==1)
            return strs[0];
        
        string res="";
        int length=0;
        
        while(true){
            bool possible=true;
            char ch=strs[0][length];
            
            for(int i=0;i<n;i++){
               if(length>=strs[i].size() || strs[i][length]!=ch){
                   possible=false;
                   break;
               }
            }
            
            if(!possible)
                break;
            
            res.push_back(ch);
            length++;
        }
        
        return res;
        
        
    }
};