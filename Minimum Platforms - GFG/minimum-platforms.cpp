// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    
    
    static bool compare(const pair<int,int>&p1,const pair<int,int>&p2){
        if(p1.first!=p2.first)
          return p1.first<p2.first;
          
          return p1.second>p2.second;
    }
    
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    	vector<pair<int,int>>time;
    	
    	for(int i=0;i<n;i++){
    	    time.push_back({arr[i],1});
    	    time.push_back({dep[i],0});
    	}
    	
    	sort(time.begin(),time.end(),compare);
    	int size=time.size();
    	
    	int minPlatforms=0;
    	int curPlatforms=0;
    	for(int i=0;i<size;i++){
    	    if(time[i].second==1)
    	    curPlatforms++;
    	    else
    	    curPlatforms--;
    	    minPlatforms=max(minPlatforms,curPlatforms);
    	}
    	
    	return minPlatforms;
    	
    	
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends