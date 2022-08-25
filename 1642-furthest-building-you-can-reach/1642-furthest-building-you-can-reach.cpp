class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n=heights.size();
        priority_queue<int>pq;
        
        int pos=0;
        
        for(int i=1;i<n;i++){
            if(heights[i-1]>=heights[i]){
                pos=i;
                continue;
            }
            else{
                int diff=heights[i]-heights[i-1];
                bricks-=diff;
                pq.push(diff);
                
                while(bricks<0 && !pq.empty() && ladders>0){
                    bricks+=pq.top();
                    pq.pop();
                    ladders--;
                }
                
                if(bricks<0)
                    return pos;
                else
                    pos=i;
                
            }
        }
        
        return pos;
        
    }
};