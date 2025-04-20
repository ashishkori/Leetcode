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
    void solve(TreeNode *root, vector<vector<int>>& res) {
        if(!root) return;
        queue<TreeNode*>q; 
        q.push(root);
        
        while(!q.empty()) {
            int size= q.size();
            vector<int> lev;
            for(int i=0;i<size;i++) {
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                lev.push_back(tmp->val);
            }
            res.push_back(lev);
           // lev.clear();
        }

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        solve(root, res);
        return res;
    }
};