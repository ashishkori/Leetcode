class Solution {
public:

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       // set<pair<int,int>> visit;
        queue<vector<int>> qu;
        qu.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int level=0;
        int m=maze.size();
        int n=maze[0].size();
        vector<int> dx={0, 0, 1, -1};
        vector<int> dy={1, -1, 0 ,0};
        while(!qu.empty()) {
            int n1=qu.size();
            while(n1) {
                vector curr=qu.front();
                qu.pop();
                int i=curr[0];
                int j=curr[1];
                if((i==0||j==0||i==m-1||j==n-1) && !(i==entrance[0] && j==entrance[1])) return level;
                for(int k=0;k<4;k++) {
                    int i_=i+dx[k];
                    int j_=j+dy[k];
                    if(i_<m && j_<n && i_>=0 && j_>=0 && maze[i_][j_]=='.') {
                        qu.push({i_,j_});
                        maze[i_][j_]='+';
                    }
                }
                n1--;
            }
            level++;
        }
        return -1;
    }
};