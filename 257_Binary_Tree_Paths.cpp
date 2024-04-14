class Solution {
public:
    void solver(TreeNode* root, vector<string> &v, string str){
        if(!root) return;
        str += to_string(root->val)+"->";
        if(root->left == NULL && root->right == NULL){
            str.pop_back();
            str.pop_back();
            v.push_back(str);
            return;
        }

        solver(root->left, v, str);
        solver(root->right, v, str);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        if(root == NULL) return vec;

        solver(root, vec, "");
        return vec;
    }
};