class Solution {
public:
    int minDepth(TreeNode* root) {
        // base case
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1; // leaf node
        int d = 0;
        int dl=0, dr=0;
        if(root->left != NULL){
            dl+=minDepth(root->left);
            if(root->right==NULL) d = dl+1;
        }

        if(root->right != NULL){
            dr+=minDepth(root->right);
            if(root->left==NULL) d = dr+1;
        }

        if(root->left != NULL && root->right != NULL) d = min(dl,dr)+1;
        return d;
    }
};