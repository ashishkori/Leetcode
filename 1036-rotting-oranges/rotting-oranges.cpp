class Solution {
private: 
    int bfs(vector<vector<int>>& grid) {
        int tm=0;
        int countFresh=0;
        //{{R C }{TM}}
        queue<pair<pair<int,int>,int>> qt;
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) countFresh++;
                if(grid[i][j]==2) { 
                    visited[i][j] = 2;
                    qt.push({{i,j},0});
                } else visited[i][j]=0;
            }
        }
        int delr[] = { 0, 1, 0, -1};
        int delc[] = {-1, 0 , 1, 0};
        while(!qt.empty()) {
            int row=qt.front().first.first;
            int col = qt.front().first.second;
            int t = qt.front().second;
            qt.pop();
            tm = max(t,tm);
            for(int i=0;i<4;i++) {
                int nrow=row+delr[i];
                int ncol=col+delc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && visited[nrow][ncol]==0) {
                    qt.push({{nrow,ncol},t+1});
                    visited[nrow][ncol]=2;
                    countFresh--;

                }
            }
        }
        if(countFresh) return -1;
        return tm;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};