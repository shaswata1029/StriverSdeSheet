class Solution {
public:
    
    string say(string &str){
        int n=str.size();
        
        string res="";
       
        
        int curIndex=0;
        while(curIndex<n)
        {
            int digit=str[curIndex]-'0';
            int count=1;
            while(curIndex+1<n && str[curIndex+1]==str[curIndex])
            {
                count++;
                curIndex++;
            }
            
            string countStr=to_string(count);
            res+=countStr;
            res.push_back('0'+digit);
            
            curIndex++;
        }
        
        return res;
    }
    
    string countAndSay(int n) {
        
        if(n==1)
            return "1";
        
        string prevSay=countAndSay(n-1);
        string curSay=say(prevSay);
        return curSay;
        
    }
};