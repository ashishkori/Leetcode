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
    int res=0;
    void solve(TreeNode* root, int step, bool left) {
        if(!root) return ;
        res=max(res,step);
        if(left){
            solve(root->left,step+1,false);
            solve(root->right,1,true);
        } else {
            solve(root->right,step+1,true);
            solve(root->left,1,false);
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root,0,true);
        return res;
    }
};