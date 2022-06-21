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

struct Profit{
  int rob,notRob;  
};

class Solution {
public:
    
    Profit findMaxProfit(TreeNode *root,int &maxProfit){
        
        if(root==NULL)
            return {0,0};
        
        Profit leftProfit=findMaxProfit(root->left,maxProfit);
        Profit rightProfit=findMaxProfit(root->right,maxProfit);
        
        int profitRob=root->val+leftProfit.notRob+rightProfit.notRob;
        int profitNotRob = max(leftProfit.rob,leftProfit.notRob)+max(rightProfit.rob,rightProfit.notRob);
        
        maxProfit=max(maxProfit,max(profitRob,profitNotRob));
        
        return {profitRob,profitNotRob};
        
    }
    
    int rob(TreeNode* root) {
        int maxProfit=0;
        
        findMaxProfit(root,maxProfit);
        
        return maxProfit;
    }
};