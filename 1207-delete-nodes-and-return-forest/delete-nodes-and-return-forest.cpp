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
     TreeNode* deleteHelper(TreeNode* root,  vector<TreeNode*>& res,unordered_set<int>& st){
        if(!root) return nullptr;

       root->left= deleteHelper(root->left,res,st);
       root->right= deleteHelper(root->right,res,st);

        if(st.find(root->val) !=st.end()) {
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            //delete root;
            return nullptr;
        } else {
            return root;
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        vector<TreeNode*> res;
        for(auto x:to_delete) {
            st.insert(x);
        }
        deleteHelper(root,res,st);

        if(st.find(root->val)==st.end()) {
            res.push_back(root);
        }
        return res;
    }
};