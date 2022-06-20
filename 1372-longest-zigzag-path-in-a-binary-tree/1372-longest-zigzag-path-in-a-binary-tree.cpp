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

struct Path{
    int left,right;
    
};

class Solution {
public:
    
    Path longestZigZagPath(TreeNode *root,int &maxPath){
        if(root==NULL)
            return {-1,-1};
        
        Path leftAns=longestZigZagPath(root->left,maxPath);
        Path rightAns=longestZigZagPath(root->right,maxPath);
        
        int leftPath=1+leftAns.right;
        int rightPath=1+rightAns.left;
        
        maxPath=max({maxPath,leftPath,rightPath});
        
        return {leftPath,rightPath};
    }
    
    int longestZigZag(TreeNode* root) {
        int maxPath=0;
        
        longestZigZagPath(root,maxPath);
        return maxPath;
    }
};