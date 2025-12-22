class Solution {
public:
    //with grid modification
    int matrixScore1(vector<vector<int>>& grid) {
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
    // Without mofidfing the grid
    int matrixScore2(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=m*pow(2,n-1);
   
         for(int j=1;j<n;j++) {
            int cz=0, co=0;
            for(int i=0;i<m;i++) {
                if(grid[i][0]==0) {
                    if(grid[i][j]==0) co++;
                    else cz++;
                } else {
                    if(grid[i][j]==1) co++;
                     else cz++;
                }
            }
            res+=(pow(2,n-j-1)*max(cz,co));
        }
        return res;
    }
    int matrixScore(vector<vector<int>>& grid) {
        return 1?matrixScore1(grid):matrixScore2(grid);
    }

};