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
    int solve(TreeNode* root, int sum, int & res) {
        if(!root) return 0;

        if(!root->left && !root->right) {
            res+=sum*10+root->val;
            return sum;
        }
        sum=sum*10+root->val;
        int l=solve(root->left,sum,res);
        int r=solve(root->right,sum,res);
        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        int res=0;
        int sum=0;
        solve(root, sum, res);
        return res;
    }
};