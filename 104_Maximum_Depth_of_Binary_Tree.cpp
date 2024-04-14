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
int depth(TreeNode* root){
    if(root == NULL) return 0;
    if(root->left == NULL & root->right == NULL) return 1;

    int height = 0;
    height = max(depth(root->left),depth(root->right)) + 1;
    return height;
}
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int ans=0;

        ans = depth(root); 
        return ans;       
    }
};