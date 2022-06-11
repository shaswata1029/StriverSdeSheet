class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>product(n,1);
        
//      Using Extra Space   
//         vector<int>leftProduct(n,1);
//         vector<int>rightProduct(n,1);
        
//         for(int i=1;i<n;i++)
//             leftProduct[i]=leftProduct[i-1]*nums[i-1];
        
        
//         for(int i=n-2;i>=0;i--)
//             rightProduct[i]=rightProduct[i+1]*nums[i+1];
        
//         for(int i=0;i<n;i++)
//             product[i]=leftProduct[i]*rightProduct[i];
        
//         Without using extra space
        
        for(int i=1;i<n;i++)
            product[i]=product[i-1]*nums[i-1];
        
        int rightProduct=1;
        for(int i=n-2;i>=0;i--){
            rightProduct=rightProduct*nums[i+1];
            product[i]=product[i]*rightProduct;
        }
        
        return product;
        
        
        
    }
};