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
 int res=0;

int Sum(TreeNode* root, int & c){
    if(root==NULL) return 0;
        c++;
    return root->val + Sum(root->left, c) + Sum(root->right, c);
}

void solve(TreeNode* root){
    if(root==NULL) return;
    int c=0;
    int sum = Sum(root,c);
    if(root->val == sum/c ) res++;         
    solve(root->left);
    solve(root->right);
 }
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        res=0;
        solve(root);
         return res;
    }
};