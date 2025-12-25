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
    void solve(TreeNode* root, int target,vector<vector<int>>& res, vector<int> path, int sum) {
        if(!root) return;
     
        sum+=root->val;
        path.push_back(root->val);
        if(!root->left && !root->right) {
            if(sum==target) res.push_back(path);
            return;
        }
        solve(root->left,target,res,path, sum);
        solve(root->right,target,res,path, sum);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        int sum=0;
        vector<int> path;
        solve(root,targetSum, res, path, sum);
        return res;
    }
};