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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr) return result;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q; ///pair{node*,pair{vl,l}
         
        q.push({root,{0,0}});
        while(!q.empty()) {
            int n=q.size();
            for(int i=0;i<n;i++) {
                TreeNode *curr=q.front().first;
                int x = q.front().second.first;
                int y = q.front().second.second;
                mp[x][y].insert(curr->val);
                q.pop();
                if(curr->left) {
                    q.push({curr->left,{x-1,y+1}});
                }
                if(curr->right) {
                    q.push({curr->right,{x+1,y+1}});
                }
            }
        }
        for(auto it:mp) {
            vector<int>col;
            for(auto q:it.second) {
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            result.push_back(col);
        }
        return result;
    }
};