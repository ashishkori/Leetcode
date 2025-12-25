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
    string solve(TreeNode* root, map<string,int>&mp, vector<TreeNode*>& res) {
        if(!root) return "N";

        string s= to_string(root->val)+","+solve(root->left,mp,res)+","+solve(root->right,mp,res);

        if(mp[s]==1) {
            res.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        map<string,int>mp;
        solve(root,mp,res);
        return res;
    }
};