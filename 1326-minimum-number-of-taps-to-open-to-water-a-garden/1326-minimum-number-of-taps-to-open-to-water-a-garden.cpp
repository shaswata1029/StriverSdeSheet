class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
         vector<pair<int,int>>range(n+1);
        
        for(int i=0;i<=n;i++){
            int start=i-ranges[i];
            int end=i+ranges[i];
            range[i]={start,end};
        }
        
        sort(range.begin(),range.end());
      
        int count=0;
        int startPoint=0;
        int curIndex=0;
        
        while(startPoint<n){
            int endPoint=startPoint;
            while(curIndex<=n && range[curIndex].first<=startPoint){
                endPoint=max(endPoint,range[curIndex].second);
                curIndex++;
            }
        
            if(endPoint<=startPoint)
                return -1;
            count++;
            startPoint=endPoint;
        }
        
        
        return count;
        
    }
};