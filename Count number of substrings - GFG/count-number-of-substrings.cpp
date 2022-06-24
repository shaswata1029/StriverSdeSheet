// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

typedef long long ll;
class Solution
{
  public:
  
  ll countAtLeastK(string &s,int n,int k){
      ll count=0;
      
      int index1=0,index2=0;
      vector<int>freq(26,0);
      int distinct=0;
      
      while(index2<n){
          
          freq[s[index2]-'a']++;
          if(freq[s[index2]-'a']==1)
          distinct++;
          
          
          if(distinct>=k){
          while(index1<=index2 && distinct>=k){
              freq[s[index1]-'a']--;
              if(freq[s[index1]-'a']==0)
               distinct--;
              
              
              index1++;
          }
              index1--;
              freq[s[index1]-'a']++;
              if(freq[s[index1]-'a']==1)
               distinct++;
          }
          
          
          
          
          
          if(distinct>=k)
          count+=(index1+1);
          
          index2++;
      }
      
      return count;
  }
    
    
    long long int substrCount (string s, int k) {
    	//code here.
    	
    	int n=s.size();
    	ll count1=countAtLeastK(s,n,k);
    	ll count2=countAtLeastK(s,n,k+1);
    	
    	ll count=count1-count2;
    	return count;
    	
    	
    }
};

// { Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}  // } Driver Code Ends