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
    map<int,int>mp;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        mp[root->val]++;
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        int maxF=0;
        vector<int> res;
        for(auto x:mp) {
            if(x.second==maxF) {
                res.push_back(x.first);
            } else if(x.second>maxF) {
                maxF=x.second;
                res={x.first};

            }
        }
        return res;
    }
};