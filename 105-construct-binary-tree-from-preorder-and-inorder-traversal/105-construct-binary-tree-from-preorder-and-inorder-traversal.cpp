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
    TreeNode * buildTree(int left,int right,vector<int>&preorder,map<int,int>&inorder,int &curIndex){
        
        if(left>right)
            return NULL;
        
        int val=preorder[curIndex];
        TreeNode *root=new TreeNode(val);
        curIndex++;
        
        int index=inorder[val];
        root->left=buildTree(left,index-1,preorder,inorder,curIndex);
        root->right=buildTree(index+1,right,preorder,inorder,curIndex);
        
        return root;
        
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=inorder.size();
        map<int,int>hashMap;
        
        for(int i=0;i<n;i++)
            hashMap[inorder[i]]=i;
        
        int curIndex=0;
        TreeNode *root =buildTree(0,n-1,preorder,hashMap,curIndex);
        return root;
        
    }
};