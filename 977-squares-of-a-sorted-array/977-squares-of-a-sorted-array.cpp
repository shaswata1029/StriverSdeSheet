class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n=nums.size();
        
        int index1=n,index2=n-1;
        
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                index1=i;
                index2=i-1;
                break;
            }
        }
        
        vector<int>squares(n);
        int cur_idx=0;
        
        while(index1<n and index2>=0){
            if(nums[index1]*nums[index1]>nums[index2]*nums[index2]){
                squares[cur_idx]=nums[index2]*nums[index2];
                index2--;
            }
            else{
                squares[cur_idx]=nums[index1]*nums[index1];
                index1++;
            }
            cur_idx++;
        }
        
        while(index1<n){
            squares[cur_idx]=nums[index1]*nums[index1];
            index1++;
            cur_idx++;
        }
        
        while(index2>=0){
            squares[cur_idx]=nums[index2]*nums[index2];
            index2--;
            cur_idx++;
        }
        
        return squares;
        
        
        
    }
};