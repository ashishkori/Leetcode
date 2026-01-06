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
    void inorder( TreeNode* root, TreeNode*& prev, int &min1) {
        if(!root) return;
        inorder(root->left,prev,min1);
        if(prev) min1=min(min1, abs(root->val-prev->val));
        prev=root;
        inorder(root->right,prev,min1);
    }
    int getMinimumDifference(TreeNode* root) {
        int min=INT_MAX;
        TreeNode* prev=nullptr;
        inorder(root,prev,min);
        return min;
    }
};