// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    static bool compare(const Job &job1,const Job &job2){
        return job1.dead<job2.dead;
        
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job jobs[], int n) 
    { 
        // your code here
        
        
        sort(jobs,jobs+n,compare);
        int curIndex=n-1;
        int maximumProfit=0;
        priority_queue<int>pq;
        int count=0;
        
        for(int i=100;i>=1;i--){
            while(curIndex>=0 and jobs[curIndex].dead==i){
            pq.push(jobs[curIndex].profit);
            curIndex--;
            }
            if(!pq.empty()){
                count++;
                maximumProfit+=pq.top();
                pq.pop();
            }
        }
        
        
        return {count,maximumProfit};
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends