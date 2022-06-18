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
    
    TreeNode* invertTree(TreeNode* root) {
        
//         Recursive Method
//         if(root==NULL)
//             return NULL;
        
//         TreeNode * newRight=invertTree(root->left);
//         TreeNode* newLeft=invertTree(root->right);
        
//         root->left=newLeft;
//         root->right=newRight;
        
//         Iterative method;
        
        if(root==NULL)
            return root;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            
            TreeNode *temp=node->left;
            node->left=node->right;
            node->right=temp;
            
          
            if(node->left)
                q.push(node->left);
            
            if(node->right)
                q.push(node->right);
            
           
        }
        
        return root;
        
    }
};