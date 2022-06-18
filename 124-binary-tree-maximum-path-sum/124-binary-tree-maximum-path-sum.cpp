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
    
    int maxPathSum(TreeNode *root,int &maxSum){
        if(root==NULL)
            return 0;
        
        int leftSum=maxPathSum(root->left,maxSum);
        int rightSum=maxPathSum(root->right,maxSum);
        
        int val=root->val;
        maxSum=max(maxSum,leftSum+rightSum+val);
        
        int pathSum=max(0,max(leftSum,rightSum)+val);
        return pathSum;
        
    }
    
    int maxPathSum(TreeNode* root) {
        
        int maxSum=INT_MIN;
        
        maxPathSum(root,maxSum);
        
        return maxSum;
        
        
    }
};