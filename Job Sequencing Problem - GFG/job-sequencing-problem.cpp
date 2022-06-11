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
       
        int maximumProfit=0;
        int count=0;
        
        priority_queue<int>pq;
        pq.push(jobs[n-1].profit);
        
        for(int i=n-2;i>=0;i--){
            int timeDiff=jobs[i+1].dead-jobs[i].dead;
            
            while(timeDiff>0 and !pq.empty()){
                count++;
                maximumProfit+=pq.top();
                pq.pop();
                timeDiff--;
            }
            
            pq.push(jobs[i].profit);
        }
        
        int timeDiff=jobs[0].dead;
        while(timeDiff>0 and !pq.empty()){
            count++;
            maximumProfit+=pq.top();
            pq.pop();
            timeDiff--;
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