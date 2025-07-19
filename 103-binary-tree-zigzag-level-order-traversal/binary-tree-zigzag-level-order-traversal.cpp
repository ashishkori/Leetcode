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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root==nullptr) return result;
        queue<TreeNode* > qu;
        qu.push(root);
        bool dir=false;
        while(!qu.empty()) {
            int n = qu.size();
            vector<int> level(n,0);
            for(int i=0;i<n;i++) {
                TreeNode* curr=qu.front();
                int index=dir?n-i-1:i;
                level[index]=curr->val;
                qu.pop();
                
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
           // if(dir) reverse(level.begin(),level.end());
            result.push_back(level);
            dir=!dir;
        }
        return result;
    }
};