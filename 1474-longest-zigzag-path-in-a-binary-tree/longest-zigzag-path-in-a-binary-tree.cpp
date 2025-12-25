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

    int longestZigZag1(TreeNode* root) {
        solve(root,0,true);
        solve(root,0,false);
        return res;
    }
    void solve2(TreeNode* root, int l, int r) { 
        if(!root) return;
        res=max(res,l);
        res=max(res,r);
        solve2(root->left,r+1,0);
        solve2(root->right,0,l+1);

    }
    int longestZigZag2(TreeNode* root) {
        solve2(root,0,0);
        return res;
    }

    int longestZigZag(TreeNode* root) {
        
        return 0?longestZigZag1(root):longestZigZag2(root);
    }
};