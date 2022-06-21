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
    
    bool isValidBST(TreeNode* root,long minVal,long maxVal){
        if(root==NULL)
            return true;
        
        if(root->val<minVal || root->val>maxVal)
            return false;
        
        return isValidBST(root->left,minVal,(long)root->val-1) && isValidBST(root->right,(long)root->val+1,maxVal);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LLONG_MIN,LLONG_MAX);
    }
};