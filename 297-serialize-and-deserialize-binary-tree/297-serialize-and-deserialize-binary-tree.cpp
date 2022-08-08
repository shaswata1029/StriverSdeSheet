/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    TreeNode* deserializeTree(vector<string>&str,int &index){
        
        if(str[index]=="NULL"){
            index++;
            return NULL;
        }
        
        int num=stoi(str[index]);
        TreeNode* root=new TreeNode(num);
        index++;
        root->left=deserializeTree(str,index);
        root->right=deserializeTree(str,index);
        return root;
    }
    
    vector<string> split(string &str,char delimeter){
        int n=str.size();
        int curIndex=0;
        
        string curStr="";
        vector<string>res;
        
        while(curIndex<n){
            
            while(curIndex<n && str[curIndex]!=delimeter){
                char ch=str[curIndex];
                curStr.push_back(ch);
                curIndex++;
            }
            
            res.push_back(curStr);
            curStr="";
            curIndex++;
        }
        
        return res;
    }

    void serializeTree(TreeNode* root,string &res){
        if(root==NULL){
            res+="NULL";
            res.push_back(',');
            return;
        }
        
        string num=to_string(root->val);
        res+=num;
        res.push_back(',');
        
        serializeTree(root->left,res);
        serializeTree(root->right,res);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string res="";
        serializeTree(root,res);
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<string> str=split(data,',');
        int index=0;
        TreeNode *root=deserializeTree(str,index);
        return root;
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));