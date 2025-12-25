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
    vector<int> rightSideView1(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> res;
        qu.push(root);
        if(!root) return {};
        while(!qu.empty()) {
            int s=qu.size();
             TreeNode* curr = NULL;
            while(s) {
                curr = qu.front();
                qu.pop();
                //if(s==1) res.push_back(curr->val);
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
                s--; 
            }
            res.push_back(curr->val);
        }
        return res;
    }
    void dfs(TreeNode* root, int level,  vector<int>& res) {
        if(!root) return;
        if(res.size()<level) {
            res.push_back(root->val);
        }
        dfs(root->right,level+1,res);
        dfs(root->left,level+1,res);

    }
    vector<int> rightSideView2(TreeNode* root) {
        vector<int> res;
        dfs(root, 1,res);
        return res;
    }

    vector<int> rightSideView(TreeNode* root) {
       return 0?rightSideView1(root):rightSideView2(root);
    }
};