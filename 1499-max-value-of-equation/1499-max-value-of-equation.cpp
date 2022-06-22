class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        
        int n=points.size();
        
        vector<int>diff(n);
        for(int i=0;i<n;i++)
            diff[i]=points[i][1]-points[i][0];
        
        deque<int>q;
        q.push_back(0);
        
        int maxAns=INT_MIN;
        int index1=0,index2=1;
        
        while(index2<n){
            while(index1<=index2 && (points[index2][0]-points[index1][0])>k){
                if(q.front()<=index1)
                    q.pop_front();
                index1++;
            }
            
            if(index1!=index2){
                int maxIndex=q.front();
                int ans=diff[maxIndex]+points[index2][0]+points[index2][1];
                maxAns=max(maxAns,ans);
            }
            
            while(!q.empty() && diff[index2]>=diff[q.back()])
                q.pop_back();
            q.push_back(index2);
            index2++;
        }
        
        return maxAns;
    }
};