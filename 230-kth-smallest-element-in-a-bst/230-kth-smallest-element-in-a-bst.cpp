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
    void findKthSmallest(TreeNode *root,int &count,int k,int &ans){
        if(root==NULL)
            return;
        
        findKthSmallest(root->left,count,k,ans);
        
        if(count==k)
            return;
        
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        
        findKthSmallest(root->right,count,k,ans);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int count=0;
        int ans=-1;
        
        findKthSmallest(root,count,k,ans);
        
        return ans;
    }
};