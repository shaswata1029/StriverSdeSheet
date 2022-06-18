struct Node * convertToMirror(struct Node *root){
    if(root==NULL)
    return NULL;
    
    struct Node *newRight=convertToMirror(root->left);
    struct Node* newLeft=convertToMirror(root->right);
    
    root->left=newLeft;
    root->right=newRight;
    
    return root;
}

void mirror(struct Node* root) {
    // code here
    
    convertToMirror(root);
}
