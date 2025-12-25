class Solution {
public:
    int n;
    int dp[201][1001];
    int solve(int idx, vector<int>& nums, int target) {
        if(target == 0) {
            return 1;
        }
        if(idx>=n || target<0) return 0;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int take = solve(0,nums,target-nums[idx]);
        int rej  = solve(idx+1,nums,target);
        return dp[idx][target]=take+rej;
    }

     int solve1(int idx, vector<int>& nums, int target) {
        if(target == 0) {
            return 1;
        }
        if(idx>=n || target<0) return 0;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int count=0;
        for(int i=idx;i<n;i++) {
            count += solve1(0,nums,target-nums[i]);
        }
        return dp[idx][target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        int count=0;
        memset(dp,-1,sizeof(dp));

        return 0?solve(0,nums,target):solve1(0,nums,target);
        //return count;
        
    }
};