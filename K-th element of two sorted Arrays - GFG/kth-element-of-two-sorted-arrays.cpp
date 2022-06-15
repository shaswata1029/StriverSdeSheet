// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    int countNumbers(int arr[],int n,int number){
        
        int low=0;
        int high=n-1;
        
        int index=-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(arr[mid]<=number){
                index=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        
        return index+1;
    }
    
    bool isPossible(int arr1[],int arr2[],int n,int m,int number,int k){
        int count=0;
        count+=countNumbers(arr1,n,number);
        
        if(count>=k)
        return true;
        
        count+=countNumbers(arr2,m,number);
        if(count>=k)
        return true;
        
        return false;
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int low=1;
        int high=INT_MAX;
        
        int ans=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(arr1,arr2,n,m,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends