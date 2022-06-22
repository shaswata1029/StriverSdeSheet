class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        
        int n=colors.size();
        int curIndex=0;
        int minCost=0;
        
        while(curIndex<n){
            char ch=colors[curIndex];
            
            int totalTime=time[curIndex];
            int maxTime=time[curIndex];
            
            while(curIndex+1<n and colors[curIndex+1]==ch)
            {
                curIndex++;
                totalTime+=time[curIndex];
                maxTime=max(maxTime,time[curIndex]);
            }
            
            minCost+=(totalTime-maxTime);
            curIndex++;
        }
        
        return minCost;
        
        
    }
};