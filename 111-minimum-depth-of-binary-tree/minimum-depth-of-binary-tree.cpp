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
    int minDepth(TreeNode* root) {
     queue<TreeNode*>qu;
        if(!root) return 0;
        qu.push(root);
        int level=1;
        while(!qu.empty()) {
            int s=qu.size();
            while(s--){
                TreeNode* curr=qu.front();
                qu.pop();
                if(!curr->left && !curr->right) return level;
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            level++;
        } 
        return 0;
    }
};