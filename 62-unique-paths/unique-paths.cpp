class Solution {
public:
    int solve2(int m, int n) {
        vector <vector<int>> dp(m,vector<int>(n));
        dp[0][0] = 1;
        vector<int>prev(n);
        //prev[0]=1;
        for(int i=0;i<m;i++) {
            vector<int> curr(n,0);
            for(int j=0;j<n;j++) {
                if(i==0 && j==0) {
                    curr[0] = 1;
                    continue;
                }else {
                    int l=0, u=0;
                    if(j>0) l=curr[j-1];
                    u=prev[j];
                    curr[j]=l+u;
                }
            }
            prev=curr;
        }
        //return dp[m-1][n-1];
        return prev[n-1];
    }
    int solve(int m, int n, vector<vector<int>>&dp) {
        if(m==0 && n==0) return 1;
        if(m<0||n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int l =solve(m-1,n, dp);
        int u =solve(m,n-1, dp);
        return dp[m][n]=l+u;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0]=1;
      //  return solve(m-1,n-1, dp);
        return solve2(m , n);
    }
};