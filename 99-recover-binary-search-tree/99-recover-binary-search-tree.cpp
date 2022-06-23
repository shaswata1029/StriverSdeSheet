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
    void inorder(TreeNode *root,TreeNode* &prev,TreeNode*&first,TreeNode*&middle,TreeNode *&last){
        if(root==NULL)
            return;
        
        inorder(root->left,prev,first,middle,last);
        
        if(prev!=NULL && (prev->val > root->val)){
//             This is the first violation,mark these two nodes as first and middle
            if(first==NULL){
                first=prev;
                middle=root;
            }
//             This is the second violation mark this node as last
            else
                last=root;
        }
        
        prev=root;
        inorder(root->right,prev,first,middle,last);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode *prev=NULL,*first=NULL,*middle=NULL,*last=NULL;
        
        inorder(root,prev,first,middle,last);
        
        if(last==NULL)
            swap(first->val,middle->val);
        else
            swap(first->val,last->val);
        
            
    }
};