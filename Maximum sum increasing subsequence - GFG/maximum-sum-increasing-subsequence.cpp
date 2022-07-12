// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int nums[], int n)  
	{  
	    // Your code goes here
	    
	    vector<int>dp(n);
	    
	    int ans=INT_MIN;
	    for(int index1=0;index1<n;index1++){
	        
	        int maxSum=0;
	        for(int index2=0;index2<index1;index2++)
	        if(nums[index1]>nums[index2])
	        maxSum=max(maxSum,dp[index2]);
	        
	        dp[index1]=maxSum+nums[index1];
	        ans=max(ans,dp[index1]);
	    }
	    
	    return ans;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends