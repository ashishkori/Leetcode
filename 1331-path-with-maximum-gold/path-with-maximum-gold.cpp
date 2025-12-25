class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n || i<0 || j<0 || !grid[i][j]) {
            return 0;
        }
        int v=grid[i][j];
       // visited[i][j]=true;
       grid[i][j]=0;
       int res=0;
        res =max(res,solve(grid,i+1,j));
        res =max(res,solve(grid,i-1,j));
        res =max(res,solve(grid,i,j+1));
        res =max(res,solve(grid,i,j-1));
        grid[i][j]=v;
        return res+v;
        //visited[i][j]=false;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
       // vector<vector<bool>> visited(m,vector<bool>(n,false));
        int res=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) {
                    res=(max(res,solve(grid,i,j)));
                }
            }
        }
        return res;
    }
};