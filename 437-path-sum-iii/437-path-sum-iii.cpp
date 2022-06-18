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
typedef long long ll;

class Solution {
public:
    int countPaths(TreeNode *root,ll targetSum){
        if(root==NULL)
            return 0;
        
        int val=root->val;
        int leftCount=countPaths(root->left,targetSum-val);
        int rightCount=countPaths(root->right,targetSum-val);
        
        int totalCount=leftCount+rightCount;
        if(targetSum==val)
            totalCount++;
        
        return totalCount;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
       if(root==NULL)
           return 0;
        
        int totalCount=0;
        totalCount+=countPaths(root,targetSum);
        totalCount+=pathSum(root->left,targetSum);
        totalCount+=pathSum(root->right,targetSum);
        
        return totalCount;
        
    }
};