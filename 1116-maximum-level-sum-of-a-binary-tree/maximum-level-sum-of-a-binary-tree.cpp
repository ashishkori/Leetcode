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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>qu;
        qu.push(root);
        int maxNode=INT_MIN;
        int lvl=-1;
        int level=0;
        while(!qu.empty()) {
            int s=qu.size();
            int sum=0;
            while(s--){
                TreeNode* curr=qu.front();
                sum+=curr->val;
                qu.pop();
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            level++;
            if(maxNode<sum) {
                maxNode=sum;
                lvl=level;
            };
            
        } 
        return lvl;
    }
};