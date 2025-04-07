class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int targetSum=0;
        for(auto x:nums) targetSum+=x;
        if(targetSum%2) return false;
        targetSum/=2;
        vector<bool> dp(targetSum+1,false);
        dp[0] = true;
        for(int num:nums) {
            for(int i=targetSum;i>=num;--i) {
                dp[i]=dp[i]||dp[i-num];
            }
        }
        return dp[targetSum];
    }

};