class Solution {
public:
    bool dfs(vector<vector<char>>& board, string const &word, int i, int j, int ind,const int m,const int n) {
        if(ind == word.size()) return true;
        if(i>=m || i<0 || j>=n || j<0) return false;
        if(board[i][j] !=word[ind]) return false;
        char prev = board[i][j];
        board[i][j]='#';
        bool res=(dfs(board,word,i+1,j,ind+1,m,n) || dfs(board,word,i-1,j,ind+1,m,n) ||
            dfs(board,word,i,j+1,ind+1,m,n) || dfs(board,word,i,j-1,ind+1,m,n));

        board[i][j]=prev;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        bool result=false;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]==word[0]) {
                    if(dfs(board,word,i,j,0,m, n)){
                        result = true;
                        break;
                    }
                }
            }
        }
        return result;
    }
};