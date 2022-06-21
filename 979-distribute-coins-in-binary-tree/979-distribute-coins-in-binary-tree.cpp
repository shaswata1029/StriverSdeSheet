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
    
    int distributeCoins(TreeNode *root,int &totalMoves){
         if(root==NULL)
            return 0;
        
        int leftCoins=distributeCoins(root->left,totalMoves);
        int rightCoins=distributeCoins(root->right,totalMoves);
        
        totalMoves+=abs(leftCoins)+abs(rightCoins);
        
        int totalCoins=root->val+leftCoins+rightCoins;
        
        return (totalCoins-1);
    }
    
    int distributeCoins(TreeNode* root) {
       
       int totalMoves=0;
        
        distributeCoins(root,totalMoves);
        
        return totalMoves;
        
    }
};