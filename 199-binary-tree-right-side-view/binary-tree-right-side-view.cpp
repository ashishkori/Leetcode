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
    void levelOrder(TreeNode* root, vector<int>& result) {
        queue<TreeNode *> qu;
        qu.push(root);
        while(!qu.empty()) {
            int n=qu.size();
            vector<int> level;
            for(int i=0;i<n;i++) {
                TreeNode * curr=qu.front();
                qu.pop();
                level.push_back(curr->val);
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            result.push_back(level.back());
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==nullptr) return result;
        levelOrder(root,result);
        return result;
    }
};