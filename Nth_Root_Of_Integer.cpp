#include<bits/stdc++.h>

bool isPossible(double number,int n, double target){
    double product=1.0;
    
    for(int i=1;i<=n;i++){
        product=product*number;
        if(product>target)
            return false;
    }
    
    return true;
}

double findNthRootOfM(int n, long long m) {
	// Write your code here.
    
    
    double low=1.0;
    double high=m*1.0;
    
    double precision=1e-7;
    
    while((high-low)>precision){
        double mid=(low+high)/2.0;
        
        if(isPossible(mid,n,m)){
            low=mid;
        }
        else
            high=mid;  
    }
    
    return low;
}
