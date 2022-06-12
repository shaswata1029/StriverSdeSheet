class Solution {
public:
    bool isPalindrome(string &str){
        int n=str.size();
        if(n==1)
            return true;
        
        int start=0;
        int end=n-1;
        
        while(start<end){
            if(str[start]!=str[end])
                return false;
            start++;
            end--;
        }
        
        return true;
    }
    
    void partition(string &s,int last_index,int cur_index,int n,vector<string>&combination,vector<vector<string>>&res){
        
        
        if(cur_index==n){
            res.push_back(combination);
            return;
        }
        
            string str=s.substr(last_index,cur_index-last_index+1);
            if(isPalindrome(str)){
                combination.push_back(str);
                partition(s,cur_index+1,cur_index+1,n,combination,res);
                combination.pop_back();
            }
        
        if(cur_index==n-1)
            return;
        
        partition(s,last_index,cur_index+1,n,combination,res);
    }
    
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string>combination;
        vector<vector<string>>res;
        
        partition(s,0,0,n,combination,res);
        return res;
    }
};