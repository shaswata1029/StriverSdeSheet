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
    void findMinDiff(TreeNode *root,int &prevVal,int &minDiff){
        if(root==NULL)
            return;
        
        findMinDiff(root->left,prevVal,minDiff);
        
        int curVal=root->val;
        if(prevVal!=-1)
            minDiff=min(minDiff,curVal-prevVal);
        
        prevVal=curVal;
        
        findMinDiff(root->right,prevVal,minDiff);
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        int prevVal=-1;
        int minDiff=INT_MAX;
        findMinDiff(root,prevVal,minDiff);
        return minDiff;
    }
};