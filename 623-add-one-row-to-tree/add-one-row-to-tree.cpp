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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) {
            TreeNode* tmp=new TreeNode(val);
            tmp->left=root;
            return tmp;
        }
        queue<TreeNode*>qu;
        qu.push(root);
        int level=0;
        while(!qu.empty()) {
            level++;
            if(level==depth-1) {
                while(!qu.empty()) {
                    TreeNode *curr=qu.front();
                    qu.pop(); 
                    TreeNode* oldLeft=curr->left;
                    TreeNode* oldRight=curr->right;
                    TreeNode* newL=new TreeNode(val);
                    TreeNode* newR=new TreeNode(val);
                    newL->left=oldLeft;
                    newR->right=oldRight;
                    curr->left=newL;
                    curr->right=newR;
                }
                break;
            } else {
                int t=qu.size();
                while(t--) {
                TreeNode *curr=qu.front();
                qu.pop();
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            }
        }
        return root;

    }
};