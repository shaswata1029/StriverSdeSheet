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
    
    int findDiameter(TreeNode *root,int &diameter){
        if(root==NULL)
            return 0;
        
        int leftMax=findDiameter(root->left,diameter);
        int rightMax=findDiameter(root->right,diameter);
        
        diameter=max(diameter,leftMax+rightMax);
        
        return 1+max(leftMax,rightMax);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter=0;
        
        findDiameter(root,diameter);
        
        return diameter;
        
    }
};