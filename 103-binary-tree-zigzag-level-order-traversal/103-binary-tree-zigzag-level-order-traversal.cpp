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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>levelOrder;
        
        if(root==NULL)
            return levelOrder;
        
        deque<TreeNode*>q;
        q.push_back(root);
        
        int curLevel=1;
        
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            
            while(size>0){
                TreeNode*node;
                
                if(curLevel%2){
                node=q.front();
                q.pop_front();
                }
                else{
                    node=q.back();
                    q.pop_back();
                }
                
                level.push_back(node->val);
                
                if(curLevel%2){
                    if(node->left)
                        q.push_back(node->left);
                   
                    if(node->right)
                        q.push_back(node->right);
                }
                else{
                    if(node->right)
                        q.push_front(node->right);
                    
                    if(node->left)
                        q.push_front(node->left);
                }
                
                size--;
            }
            
            levelOrder.push_back(level);
            curLevel++;
            
        }
        
        return levelOrder;
    }
};