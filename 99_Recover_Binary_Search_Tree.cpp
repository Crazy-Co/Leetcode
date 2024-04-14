class Solution {
public:
    void solveInorder(TreeNode* root, vector<TreeNode*> &vec){
        if(root == NULL){
            return;
        }

        solveInorder(root->left, vec);
        vec.push_back(root);
        solveInorder(root->right, vec);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> ans;
        solveInorder(root, ans);

        TreeNode* first = NULL;
        TreeNode* second = NULL;

        for(int i=1; i<ans.size(); i++){
            if(ans[i - 1]->val > ans[i]->val) {
                if (!first) first = ans[i - 1];
                second = ans[i];
            }
        }

        swap(first->val, second->val);
    }
};