class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;

        if(val == root->val) return root;
        else if(val > root->val) return searchBST(root->right, val);
        else if(val < root->val) return searchBST(root->left, val);
        return new TreeNode(0);
        
        // while(root){
        //     if(root->val == val) return root;
        //     else if(root->val > val) root = root->left;
        //     else if(root->val < val) root = root->right;
        // }
        // return NULL;
    }
};