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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>>qu;
        qu.push({root,0});
        unsigned long long maxNode=0;
        while(!qu.empty()) {
            int s=qu.size();
            unsigned long long  L=qu.front().second;
            unsigned long long  R=qu.back().second;
            maxNode=max(maxNode,(R-L)+1);
            while(s--){
                TreeNode* curr=qu.front().first;
                unsigned long long idx=qu.front().second;
                qu.pop();
                if(curr->left) qu.push({curr->left, 2*idx+1});
                if(curr->right) qu.push({curr->right, 2*idx+2});
            }
        } 
        return maxNode;
    }
};