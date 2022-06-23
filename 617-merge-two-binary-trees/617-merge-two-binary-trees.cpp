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
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
       if(root1==NULL && root2==NULL)
           return NULL;
        
        int newVal=(root1==NULL?0:root1->val)+(root2==NULL?0:root2->val);
        
        if(root1==NULL){
            root2->val=newVal;
            root2->left=mergeTrees(root1,root2->left);
            root2->right=mergeTrees(root1,root2->right);
            return root2;
        }
        
        root1->val=newVal;
        root1->left=mergeTrees(root1->left,(root2==NULL?root2:root2->left));
        root1->right=mergeTrees(root1->right,(root2==NULL?root2:root2->right));
        return root1;
        
        
    }
};