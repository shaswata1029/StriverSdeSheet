// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int length) {
        //code here
        
        vector<int>dp(length+1);
        dp[1]=price[0];
        
        for(int curLength=2;curLength<=length;curLength++){
            dp[curLength]=price[curLength-1];
            int leftLength=1;
            int rightLength=curLength-1;
            
            while(leftLength<=rightLength){
                dp[curLength]=max(dp[curLength],dp[leftLength]+dp[rightLength]);
                leftLength++;
                rightLength--;
            }
        }
        
        
        return dp[length];
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends