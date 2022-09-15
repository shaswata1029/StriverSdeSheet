/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void Kdown(TreeNode* root,int k,TreeNode* blockNode,vector<int>&res){
        
        if(root==NULL || k<0 || root==blockNode)
            return;
        
        if(k==0){
            res.push_back(root->val);
            return;
        }
        
        Kdown(root->left,k-1,blockNode,res);
        Kdown(root->right,k-1,blockNode,res);
        
    }
    
    int dfs(TreeNode* root,TreeNode *target,int k,vector<int>&res){
        if(root==NULL)
            return -1;
        
        if(root==target){
            Kdown(root,k,NULL,res);
            return 1;
        }
        
        int left=-1,right=-1;
        left=dfs(root->left,target,k,res);
        
        if(left==-1)
            right=dfs(root->right,target,k,res);
        else{
            Kdown(root,k-left,root->left,res);
            return left+1;
        }
        
        if(right!=-1)
        {
            Kdown(root,k-right,root->right,res);
            return right+1;
        }
        
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int>res;
        dfs(root,target,k,res);
        
        return res;
        
    }
};