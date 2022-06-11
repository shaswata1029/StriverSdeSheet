class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        int left=0;
        int right=n-1;
        
      
        
        int maxAns=0;
        while(left<right){
            maxAns=max(maxAns,min(height[left],height[right])*(right-left));
            
//             Since left height will always be the minimum how much the right height increase we cant find a better answer with this left pointer.
//             So we increase the left pointer
//             Same is the case for right pointer 
            if(height[right]>=height[left])
                left++;
            else
                right--;
            
        }
        
        return maxAns;
        
        
    }
};