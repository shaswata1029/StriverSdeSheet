class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        vector<unordered_map<long long,int>>dp(n);
        vector<unordered_map<long long,int>>count(n);
        
        int totalCount=0;
        for(int index1=1;index1<n;index1++){
            
            for(int index2=index1-1;index2>=0;index2--){
                
                long long diff=(long long)nums[index1]-nums[index2];
                
                if(dp[index2].find(diff)!=dp[index2].end()){
                    dp[index1][diff]+=dp[index2][diff];
                }
                
                if(count[index2].find(diff)!=count[index2].end()){
                    dp[index1][diff]+=count[index2][diff];
                }
                
                count[index1][diff]++;
                  
            }
            
            for(auto &ele:dp[index1])
                totalCount+=ele.second;
            
          
        }
        
        
        return totalCount;
        
    }
};