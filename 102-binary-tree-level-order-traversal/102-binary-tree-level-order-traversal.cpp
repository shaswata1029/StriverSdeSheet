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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>levelorder;
            
        if(root==NULL)
            return levelorder;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            
            int size=q.size();
            vector<int>curLevel;
            
            while(size>0){
                TreeNode *node=q.front();
                q.pop();
                curLevel.push_back(node->val);
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
                
                size--;
            }
            levelorder.push_back(curLevel);
        }
        
        
        return levelorder;
        
    }
};