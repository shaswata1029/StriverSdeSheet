class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int element1=INT_MIN,element2=INT_MIN;
        int count1=0,count2=0;
        
        
        for(int i=0;i<n;i++){
            if(nums[i]==element1)
                count1++;
            else if(nums[i]==element2)
                count2++;
            else if(count1==0){
                element1=nums[i];
                count1=1;
            }
            else if(count2==0)
            {
                element2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        vector<int>res;
        count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==element1)
                count1++;
            else if(nums[i]==element2)
                count2++;
        }
        
        if(count1>n/3)
            res.push_back(element1);
        if(count2>n/3)
            res.push_back(element2);
        
        return res;
    }
};