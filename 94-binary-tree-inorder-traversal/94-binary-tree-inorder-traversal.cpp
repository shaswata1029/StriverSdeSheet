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
    
    void  inorderTraversal(TreeNode *root,vector<int>&inorder){
        if(root==NULL)
            return;
        
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>inorder;
//         Recursive method
//         inorderTraversal(root,inorder);
        
//         Inorder method(Using Stacks)
        
        TreeNode *node=root;
        stack<TreeNode*>st;
        
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }else{
                
                if(st.empty())
                    break;
                
                node=st.top();
                st.pop();
                
                inorder.push_back(node->val);
                node=node->right;
            }
        }
       
        return inorder;
        
        
    }
};