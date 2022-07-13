// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int MOD=1003;
   
   int dp[201][201][2];
   int countWays(string &str,int n,int state,int left,int right){
       
       if(left==right){
           if(str[left]=='T' && state==1)
           return 1;
           else if(str[left]=='F' && state==0)
           return 1;
           
           return 0;
       }
       
       if(dp[left][right][state]!=-1)
       return dp[left][right][state];
       
       int count=0;
       for(int index=left;index<right;index+=2){
           if(str[index+1]=='&'){
             if(state==1){
           count+=countWays(str,n,1,left,index)*countWays(str,n,1,index+2,right);
             }
             else{
                 count+=countWays(str,n,1,left,index)*countWays(str,n,0,index+2,right);
                 count+=countWays(str,n,0,left,index)*countWays(str,n,1,index+2,right);
                 count+=countWays(str,n,0,left,index)*countWays(str,n,0,index+2,right);
             }
           }
           else if(str[index+1]=='|'){
               if(state==1){
                  count+=countWays(str,n,1,left,index)*countWays(str,n,1,index+2,right);
                  count+=countWays(str,n,1,left,index)*countWays(str,n,0,index+2,right);
                  count+=countWays(str,n,0,left,index)*countWays(str,n,1,index+2,right);
               }
               else{
               count+=countWays(str,n,0,left,index)*countWays(str,n,0,index+2,right);
               }
           }
           else{
               if(state==1){
                  count+=countWays(str,n,1,left,index)*countWays(str,n,0,index+2,right);
                  count+=countWays(str,n,0,left,index)*countWays(str,n,1,index+2,right);
               }else{
                   count+=countWays(str,n,1,left,index)*countWays(str,n,1,index+2,right);
                  count+=countWays(str,n,0,left,index)*countWays(str,n,0,index+2,right);
               }
               
             
           }
           
           count=count%MOD;
       }
       
       return dp[left][right][state]=count;
   }

   
    int countWays(int n, string str){
        // code here
        
        memset(dp,-1,sizeof(dp));
        int ans=countWays(str,n,1,0,n-1);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends