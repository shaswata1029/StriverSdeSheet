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
    void flattenTree(TreeNode *root,TreeNode *&prevNode){
        if(root==NULL)
            return;
        
        flattenTree(root->right,prevNode);
        flattenTree(root->left,prevNode);
        
        root->right=prevNode;
        root->left=NULL;
        
        prevNode=root;
        
    }
    
    void flatten(TreeNode* root) {
        TreeNode *prevNode=NULL;
        flattenTree(root,prevNode);
        
       
    }
};