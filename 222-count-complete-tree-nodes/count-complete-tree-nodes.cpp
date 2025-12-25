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
    int getLeftH(TreeNode* root){
        if(!root) return 0;
        int i=1;
        while(root->left) {
            i++;
            root=root->left;
        }
        return i;
    }
    int getRightH(TreeNode* root) {
        if(!root) return 0;
        int i=1;
        while(root->right) {
            i++;
            root=root->right;
        }
        return i;
    }
    int solve(TreeNode* root) {
        if(!root)
            return 0;

        int lh=getLeftH(root);
        int rh=getRightH(root);
        if(rh==lh) return pow(2,lh)-1;
        return solve(root->left)+solve(root->right)+1;
    }
    int countNodes(TreeNode* root) {
        return solve(root);
    }
};