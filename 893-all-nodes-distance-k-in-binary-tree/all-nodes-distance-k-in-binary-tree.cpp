/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeChildParent(TreeNode* root,map<TreeNode*,TreeNode*>&mp){
        if(root==NULL) return;
        if(root->left) {
            mp[root->left]=root;
            makeChildParent(root->left,mp);
        }
        
        if(root->right) {
            mp[root->right]=root;
            makeChildParent(root->right,mp);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode *, TreeNode *> childParrent;
        childParrent[root] = NULL;
        makeChildParent(root,childParrent);
        queue<TreeNode*> q;
        map<TreeNode*,bool>visited;
        q.push(target);
        int dist=0;
        while(!q.empty()) {
            int n=q.size();
            if(dist==k) break;
            for(int i=0;i<n;i++) {
                TreeNode* curr=q.front();
                visited[curr]=true;
                q.pop();
                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                }
                
                if(curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                }
                
                if(childParrent[curr] && !visited[childParrent[curr]]) {
                    q.push(childParrent[curr]);
                }
            
            }
            ++dist;
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        //result.insert(result.end(),q.begin(),q.end());
        return result;
    }
};