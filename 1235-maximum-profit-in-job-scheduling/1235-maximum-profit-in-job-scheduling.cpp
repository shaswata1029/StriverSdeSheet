struct Job{
  int startTime,endTime,profit;  
};

class Solution {
public:
    
    static bool compare(const Job &job1,const Job &job2){
        return job1.startTime<job2.startTime;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n=startTime.size();
        
        vector<Job>jobs(n);
        
        for(int i=0;i<n;i++){
            jobs[i]={startTime[i],endTime[i],profit[i]};
        }
        
        sort(jobs.begin(),jobs.end(),compare);
        sort(startTime.begin(),startTime.end());
        
        
        vector<int>dp(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            int curEndTime=jobs[i].endTime;
            
            int nextIndex=lower_bound(startTime.begin(),startTime.end(),curEndTime)-startTime.begin();
            dp[i]=jobs[i].profit+dp[nextIndex];
            dp[i]=max(dp[i],dp[i+1]);
        }
        
        return dp[0];
        
        
    }
};