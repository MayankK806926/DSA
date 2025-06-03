//PREORDER TRAVERSAL
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preord;
    if(!root) return preord;
    TreeNode* curr=root;
    while(curr){
        if(!curr->left){
            preord.push_back(curr->val);
            curr=curr->right;
        }else{
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }

            if(!prev->right){
                prev->right=curr;
                preord.push_back(curr->val);
                curr=curr->left;
            }else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return preord;
}

//INORDER TRAVERSAL
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inord;
    if(!root) return inord;
    TreeNode* curr=root;
    while(curr){
        if(!curr->left){
            inord.push_back(curr->val);
            curr=curr->right;
        }else{
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }

            if(!prev->right){
                prev->right=curr;
                curr=curr->left;
            }else{
                prev->right=NULL;
                inord.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return inord;
}
