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
    bool isCompleteTree(TreeNode* root) {
        bool isNull=false;
        queue<TreeNode*> qu;

        qu.push(root);
        while(!qu.empty()) {
            TreeNode* curr=qu.front();
            qu.pop();
            if(curr==nullptr) {
                isNull=true;
            } else {
                if(isNull) return false;
                qu.push(curr->left);
                qu.push(curr->right);
            }     
        }
        return true;
    }
};