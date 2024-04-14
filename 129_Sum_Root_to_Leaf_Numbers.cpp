class Solution {
public:
    void solver(TreeNode* root, int &sum, int tsum){
        if(!root) return;
        tsum = tsum*10+root->val; //495
        if(root->left == NULL && root->right == NULL){
            sum += tsum;
            return;
        }
        solver(root->left, sum, tsum);
        solver(root->right, sum, tsum);
    }

    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = 0;
        solver(root, sum, 0);
        return sum;
    }
};