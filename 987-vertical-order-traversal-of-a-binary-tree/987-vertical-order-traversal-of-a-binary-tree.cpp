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
    
    void verticalTraversal(TreeNode* root,int level,int column,map<int,vector<pair<int,int>>>&hashMap){
        if(root==NULL)
            return;
        
        hashMap[column].push_back({level,root->val});
        verticalTraversal(root->left,level+1,column-1,hashMap);
        verticalTraversal(root->right,level+1,column+1,hashMap);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>hashMap;
        
        verticalTraversal(root,0,0,hashMap);
        
        vector<vector<int>>verticalOrder;
        for(auto &ele:hashMap){
            auto &v=ele.second;
            sort(v.begin(),v.end());
            
            vector<int>temp;
            for(auto val:v){
                temp.push_back(val.second);
            }
            
            verticalOrder.push_back(temp);
        }
        
        return verticalOrder;
    }
};