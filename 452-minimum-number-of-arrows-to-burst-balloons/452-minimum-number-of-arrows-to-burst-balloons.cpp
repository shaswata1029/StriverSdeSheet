class Solution {
public:
    
    static bool compare(vector<int>&point1,vector<int>&point2){
        return point1[1]<point2[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n=points.size();
        sort(points.begin(),points.end(),compare);
        
        int minArrows=1;
        int endPoint=points[0][1];
        
        for(int i=1;i<n;i++){
           
            if(points[i][0]>endPoint){
                minArrows++;
                endPoint=points[i][1];
            }
        }
        
        return minArrows;
        
    }
};