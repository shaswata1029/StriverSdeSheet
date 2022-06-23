typedef long long ll;
class Solution {
public:
      ll POS_MAX=INT_MAX;
      ll NEG_MIN=INT_MIN;
    
    int myAtoi(string str) {
        
        int n=str.size();
        ll number=0;
        
        bool positive=true;
        int curIndex=0;
        
        
        while(curIndex<n and str[curIndex]==' ')
            curIndex++;
        
        if(curIndex==n)
            return 0;
        
        if(!(isdigit(str[curIndex]) || str[curIndex]=='+' || str[curIndex]=='-'))
            return 0;
        
        if(str[curIndex]=='+')
            curIndex++;
        else if (str[curIndex]=='-')
        {
            positive=false;
            curIndex++;
        }
        
        while(curIndex<n and isdigit(str[curIndex])){
            int digit=str[curIndex]-'0';
            number=number*10+digit;
            
            cout<<number<<" ";
            if(positive and number>=POS_MAX)
            {
                number=POS_MAX;
                break;
            }
            else if(!positive and number>=(-NEG_MIN)){
                number=-NEG_MIN;
                break;
            }
            curIndex++;
        }
        
        if(!positive)
            number=-number;
        
        return (int)number;
    }
};