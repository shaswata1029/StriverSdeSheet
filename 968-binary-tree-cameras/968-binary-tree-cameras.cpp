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
    
    int minCameras(TreeNode *root,int &totalCameras){
        if(root==NULL)
            return 1;
        
        int leftAns=minCameras(root->left,totalCameras);
        int rightAns=minCameras(root->right,totalCameras);
        
        if(leftAns==-1 || rightAns==-1)
        {
            totalCameras++;
            return 0;
        }
        
        if(leftAns==0 || rightAns==0)
            return 1;
        
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        
        int totalCameras=0;
        
        int rootAns=minCameras(root,totalCameras);
        if(rootAns==-1)
            totalCameras++;
        
        return totalCameras;
    
    }
};