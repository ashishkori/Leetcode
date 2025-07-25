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
    void inOrder(TreeNode* root, int &k, int &result) {
        if(root == nullptr) return;
        inOrder(root->left,k,result);
        if(!(--k)) result = root->val;
        inOrder(root->right,k,result);
    }
    int kthSmallest(TreeNode* root, int k) {
        int result=0;
        inOrder(root,k,result);
        return result;
    }
};