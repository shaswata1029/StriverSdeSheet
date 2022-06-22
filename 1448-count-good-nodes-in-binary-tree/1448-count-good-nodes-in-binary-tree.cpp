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
    int countGoodNodes(TreeNode *root,int maxVal){
        if(root==NULL)
            return 0;
        
        int curVal=root->val;
        int count=0;
        
        if(curVal>=maxVal)
            count++;
        
        int newMaxVal=max(maxVal,curVal);
        count+=countGoodNodes(root->left,newMaxVal);
        count+=countGoodNodes(root->right,newMaxVal);
        
        return count;
    }
    
    int goodNodes(TreeNode* root) {
        int maxVal=INT_MIN;
        int count=countGoodNodes(root,maxVal);
        return count;
    }
};