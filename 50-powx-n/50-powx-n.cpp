typedef long long ll;
class Solution {
public:
    
    double binaryExp(double x,ll n){
        if(n==0)
            return 1;
        if(n==1)
            return x;
         
        double powValue=binaryExp(x,n/2);
        powValue=powValue*powValue;
        if(n%2)
            powValue=powValue*x;
        return powValue;
    }
    
    double myPow(double x, int n) {
        
        double powValue=binaryExp(fabs(x),abs((ll)n));
        
        if(n<0)
            powValue=1/powValue;
        
        
        if(x<0 and abs(n%2)==1)
            powValue=-powValue;
        
        return powValue;
      
    }
};