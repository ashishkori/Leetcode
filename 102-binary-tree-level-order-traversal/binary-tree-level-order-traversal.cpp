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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> qu;
        if(root==nullptr) return result;
        qu.push(root);
        while(!qu.empty()) {
            int n = qu.size();
            vector<int> tmp;
            for(int i=0;i<n;i++) {
                TreeNode *curr = qu.front();
                qu.pop();
                tmp.push_back(curr->val);
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            result.push_back(tmp);
        }
        return result;
    }
};