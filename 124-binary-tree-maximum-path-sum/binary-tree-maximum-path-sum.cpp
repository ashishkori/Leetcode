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
    int findSum(TreeNode* root, int& sum) {
        if(root==nullptr) return 0;
        int l=max(0,findSum(root->left,sum));
        int r=max(0,findSum(root->right,sum));
        sum = max(sum,l+r+root->val);
        return max(l,r)+root->val; 

    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        findSum(root,sum);
        return sum;
    }
};