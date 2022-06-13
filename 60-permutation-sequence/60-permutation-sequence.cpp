class Solution {
public:
    
    void findKthPermutation(int n,int k,string &permutation,vector<int>&nums,vector<int>&factorial){
        
        if(n==0)
            return;
        
        int curPos=(k+factorial[n-1]-1)/factorial[n-1];
        int newK=k-(curPos-1)*factorial[n-1];
        
        int index=0;
        
        while(curPos>0){
            if(nums[index]==0)
            curPos--;
            index++;
        }
        
        nums[index-1]=1;
        permutation.push_back('0'+index);
        
        findKthPermutation(n-1,newK,permutation,nums,factorial);
    }
    
    string getPermutation(int n, int k) {
        
        string permutation="";
        
        vector<int>factorial(n,1);
        vector<int>nums(n,0);
        
        for(int i=1;i<n;i++)
            factorial[i]=factorial[i-1]*i;
        findKthPermutation(n,k,permutation,nums,factorial);
        
        return permutation;
    }
};