
class Solution {
public:
    bool solve(TreeNode* root, int target, int sum){
        if(!root) return false;

        sum+=root->val;
        if(!root->left && !root->right) {
            if(target==sum) return true;
        }
        bool l=solve(root->left,target,sum);
        bool r=solve(root->right,target,sum);
        return l|r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum,0);
    }
};