class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root == NULL) return v;
        
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            v.push_back(level);
        }

        return v;
    }
};