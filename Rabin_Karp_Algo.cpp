// Rabin_Karp Algorithm for Pattern Matching

#include<bits/stdc++.h>
typedef long long ll;
vector<int> stringMatch(string &str, string &pattern) {
    // Write your code here
    
    int prime=37;
    int MOD=1e9+7;
    
    int n=str.size();
    int m=pattern.size();
    
    vector<ll>primePower(n,1);
    
    for(int i=1;i<n;i++)
        primePower[i]=(primePower[i-1]*prime)%MOD;
    
    vector<ll>hash(n);
    
    for(int i=0;i<n;i++){
        char ch=str[i];
        hash[i]=((i==0?0:hash[i-1])+(ch-'A'+1)*primePower[i])%MOD;
    }
    
    ll patternHash=0;
    
    for(int i=0;i<m;i++){
        char ch=pattern[i];
        patternHash=(patternHash+(ch-'A'+1)*primePower[i])%MOD;
    }
    
   vector<int>res;
    for(int i=0,j=m-1;j<n;i++,j++){
        ll currentHash=hash[j]-(i==0?0:hash[i-1]);
        currentHash=(currentHash+MOD)%MOD;
        
        if(currentHash==patternHash)
           res.push_back(i);
        
        patternHash=(patternHash*prime)%MOD;
    }
    
    return res;
}
