#include<bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
    // TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

void preorder(TreeNode* root, vector<int> &v){
    if(root == NULL) return;
    v.push_back(root->val);
    preorder(root->left,v);
    preorder(root->right,v);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;
    preorder(root,vec);
    return vec;
}

int main(){
    // TreeNode* root,a,b,c,d,e,f;
    // root->val = 1;
    // a->val = 2;
    // b->val = 3;
    // c->val = 4;
    // d->val = 5;
    // e->val = 6;
    // f->val = 7;
    // root->left = a;
    // root->right = b;
    // a->left = c;
    // a->right = d;
    // b->left = e;
    // b->right = f;


    // vector<int> v = preorderTraversal(root);

    // for(auto i: v){
    //     cout<<i<<" ";
    // }   cout<<endl;
   
    return 0;
}