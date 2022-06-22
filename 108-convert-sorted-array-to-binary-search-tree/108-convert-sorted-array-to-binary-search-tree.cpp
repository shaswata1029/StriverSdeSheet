/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *convertToBst(vector<int>&nums,int low,int high){
        if(low>high)
            return NULL;
        
        int mid=(low+high)/2;
        
        int curVal=nums[mid];
        TreeNode * node=new TreeNode(curVal);
        node->left=convertToBst(nums,low,mid-1);
        node->right=convertToBst(nums,mid+1,high);
        
        return node;    
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n=nums.size();
        TreeNode * root=convertToBst(nums,0,n-1);
        return root;
        
    }
};