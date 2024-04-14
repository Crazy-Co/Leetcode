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
    int leftLeaves(TreeNode* root){
        if(root->left == NULL && root->right == NULL) return 0;
        if(root->left == NULL && root->right != NULL) return leftLeaves(root->right);
        if(root->left != NULL && root->right == NULL){
            if(root->left->left==NULL && root->left->right==NULL) return root->left->val;
            return leftLeaves(root->left);
        } 
        if(root->left != NULL && root->right !=NULL){
            if(root->left->left==NULL && root->left->right==NULL) return root->left->val + leftLeaves(root->right);
            return leftLeaves(root->left) + leftLeaves(root->right);
        }
        return 0;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)return 0;
        int sum = 0;
        sum = leftLeaves(root);
        return sum;
    }
};