class Solution {
public:
    void generateParenthesis(int index,int n,int diff,string &parentheses,vector<string>&res){
        if(diff<0 || diff>n)
            return;
        
        if(index==2*n){
            if(diff==0)
                res.push_back(parentheses);
            return;
        }
        
        parentheses.push_back('(');
        generateParenthesis(index+1,n,diff+1,parentheses,res);
        parentheses.pop_back();
        
        parentheses.push_back(')');
        generateParenthesis(index+1,n,diff-1,parentheses,res);
        parentheses.pop_back();
        
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        string parentheses="";
        vector<string>res;
        
        generateParenthesis(0,n,0,parentheses,res);
        
        return res;
        
    }
};