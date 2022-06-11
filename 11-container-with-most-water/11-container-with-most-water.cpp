class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        int left=0;
        int right=n-1;
        
        int leftMax=INT_MIN,rightMax=INT_MIN;
        int leftIdx=-1,rightIdx=n;
        
        int maxAns=0;
        while(left<right){
            if(height[left]>leftMax){
                leftMax=height[left];
                leftIdx=left;
            }
            
            if(height[right]>rightMax){
                rightMax=height[right];
                rightIdx=right;
            }
            
            if(rightMax>=leftMax){
                maxAns=max(maxAns,leftMax*(rightIdx-leftIdx));
                left++;
            }
            else{
                maxAns=max(maxAns,rightMax*(rightIdx-leftIdx));
                right--;
            }
            
        }
        
        return maxAns;
        
        
    }
};