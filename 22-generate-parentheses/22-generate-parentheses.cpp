class Solution {
public:
    void generateParenthesis(int index,int n,int depth,string &parentheses,vector<string>&res){
        if(depth<0 || depth>n)
            return;
        
        if(index==2*n){
            if(depth==0)
                res.push_back(parentheses);
            return;
        }
        
        parentheses.push_back('(');
        generateParenthesis(index+1,n,depth+1,parentheses,res);
        parentheses.pop_back();
        
        parentheses.push_back(')');
        generateParenthesis(index+1,n,depth-1,parentheses,res);
        parentheses.pop_back();
        
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        string parentheses="";
        vector<string>res;
        
        generateParenthesis(0,n,0,parentheses,res);
        
        return res;
        
    }
};