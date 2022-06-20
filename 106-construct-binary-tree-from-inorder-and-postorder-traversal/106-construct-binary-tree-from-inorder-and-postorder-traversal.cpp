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
    TreeNode* buildTree(int left,int right,vector<int>&postorder,map<int,int>&inorderMap,int &postOrderIndex){
        
        if(left>right)
            return NULL;
        
        int val=postorder[postOrderIndex];
        TreeNode* root=new TreeNode(val);
        postOrderIndex--;
        
        int index=inorderMap[val];
        
        root->right=buildTree(index+1,right,postorder,inorderMap,postOrderIndex);
        root->left=buildTree(left,index-1,postorder,inorderMap,postOrderIndex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        map<int,int>inorderMap;
        
        for(int i=0;i<n;i++)
            inorderMap[inorder[i]]=i;
        
        int postOrderIndex=n-1;
        
        TreeNode* root=buildTree(0,n-1,postorder,inorderMap,postOrderIndex);
        return root;
        
    }
};