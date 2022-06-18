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
    void findPaths(TreeNode *root,int targetSum,vector<int>&path,vector<vector<int>>&resPath){
       
        if(root==NULL)
            return;
    
        
        int val=root->val;
        
        path.push_back(val);
        
        findPaths(root->left,targetSum-val,path,resPath);
        findPaths(root->right,targetSum-val,path,resPath);
        
        if(root->left==NULL && root->right==NULL && targetSum-val==0){
            resPath.push_back(path);
        }
        
        path.pop_back();
           
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        vector<vector<int>>resPath;
        
        findPaths(root,targetSum,path,resPath);
        return resPath;
    }
};