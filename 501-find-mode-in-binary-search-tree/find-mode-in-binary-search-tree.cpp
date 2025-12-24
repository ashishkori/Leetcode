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
    vector<int> result;
    int maxF=0;
    int currE=0;
    int currF=0;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        mp[root->val]++;
        dfs(root->right);
    }
    vector<int> findMode1(TreeNode* root) {
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
    void dfs2(TreeNode* root) {
        if(!root) return;
        dfs2(root->left);
        if(root->val == currE) {
             currF++;
        } else {
            currE=root->val;
            currF=1;
        }
        
        if(currF>maxF) {
            maxF=currF;
            result={currE};
        }else if(currF==maxF) result.push_back(currE);

        dfs2(root->right);
    }
    vector<int> findMode2(TreeNode* root) { 
        dfs2(root);

        return result;
    }
    vector<int> findMode(TreeNode* root) {
        return 0?findMode1(root):findMode2(root);
    }
};