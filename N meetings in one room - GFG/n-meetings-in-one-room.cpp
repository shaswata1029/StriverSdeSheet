// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    static bool compare(const pair<int,int>&p1,const pair<int,int>&p2){
        return p1.second<p2.second;
    }
    
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>time;
        
        for(int i=0;i<n;i++){
            int startTime=start[i];
            int endTime=end[i];
            time.push_back({startTime,endTime});
        }
        
        sort(time.begin(),time.end(),compare);
        
        int endTime=-1;
        
        int count=0;
        for(int i=0;i<n;i++){
            if(time[i].first>endTime){
                count++;
                endTime=time[i].second;
            }
            
        }
        
        return count;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends