class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int cur_element=INT_MIN;
        int count=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==cur_element)
                count++;
            else if(count==0){
                cur_element=nums[i];
                count=1;
            }
            else
                count--;
        }
        
        return cur_element;
        
    }
};