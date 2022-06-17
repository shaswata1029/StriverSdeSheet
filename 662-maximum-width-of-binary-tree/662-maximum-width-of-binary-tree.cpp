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
    int widthOfBinaryTree(TreeNode* root) {
         
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        
        ll ans=0;
        
        while(!q.empty()){
            int size=q.size();
            
            ll minIndex=q.front().second,maxIndex=LLONG_MIN;
            
            while(size>0){
                auto ele=q.front();
                q.pop();
                TreeNode* node=ele.first;
                ll curIndex=ele.second;
                
                maxIndex=max(maxIndex,curIndex);
                
                if(node->left)
                    q.push({node->left,2*(curIndex-minIndex)+1});
                
                if(node->right)
                    q.push({node->right,2*(curIndex-minIndex)+2});

                size--;
            }
            
            ans=max(ans,maxIndex-minIndex+1);
        }
        
        
        return (int)ans;
        
    }
};