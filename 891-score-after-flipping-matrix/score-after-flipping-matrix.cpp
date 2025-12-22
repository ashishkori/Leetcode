class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++) {
            bool flip=grid[i][0]?false:true;
            for(int j=0;j<n;j++) {
                if(flip) grid[i][j]=! grid[i][j];
            }
        }
        for(int j=0;j<n;j++) {
            int cz=0, co=0;
            for(int i=0;i<m;i++) {
                if(grid[i][j]) co++;
                else cz++;
            }
            if(cz>co) {
                for(int i=0;i<m;i++) {
                grid[i][j]=!grid[i][j];
                }
            }
        }
        int res=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
               res+=pow(2,n-j-1)*grid[i][j];
            }
        }
        return res;
    }
};