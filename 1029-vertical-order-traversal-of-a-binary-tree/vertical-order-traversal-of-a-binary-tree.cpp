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
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>> res;
        queue<pair<TreeNode *,pair<int,int>>> qu;
        qu.push({root,{0,0}});
        while(!qu.empty()) {
            auto t=qu.front();
            qu.pop();
            TreeNode* node = t.first;
            int ver = t.second.first;
            int lvl = t.second.second;
            //cout<<"inserting "<< node->val <<endl; 
            res[ver][lvl].insert(node->val);
            if(node->left) {
                qu.push({node->left,{ver-1,lvl+1}});
            } 
            if(node->right) {
                qu.push({node->right,{ver+1,lvl+1}});
            }
        }
        for(auto tmp:res) {
            vector<int>col;
            for(auto q:tmp.second) {
             //   cout<< q.second.size()<<endl;
                col.insert(col.end(), q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
    return ans;

    }
};