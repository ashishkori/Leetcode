class Solution {
public:
    /* 
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int rowd=row;
        int cold=col;
        while(col>=0 && row>=0) {
            if(board[row--][col--] == 'Q') return false;
        }
        row = rowd;
        col = cold;
        while(col>=0) {
            if(board[row][col--]=='Q') return false;
        }
        row = rowd;
        col = cold;
        while(col>=0 && row<n) {
            if(board[row++][col--]=='Q') return false;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &res, int n) {
        if (col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++) {
            if(isSafe(row,col,board,n)) {
                board[row][col]='Q';
                solve(col+1,board,res,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> res;
        string s(n,'.');
        for(int i=0;i<n;i++) {
            board[i]=s;
        }
        solve(0,board,res,n);
        return res;

    }
    */
    /* Optimize way using hasing */
    void solve(int col, vector<string> &board, vector<vector<string>> &res, int n, vector<bool> &left, vector<bool> &upperDiagnonal, vector<bool> &lowerDiagnonal) {
        if (col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++) {
            if(!left[row] && !lowerDiagnonal[row+col] && !upperDiagnonal[n-1+row-col] ) {
                board[row][col]='Q';
                left[row] = true;
                lowerDiagnonal[row+col] = true;
                upperDiagnonal[n-1+row-col] =true;
                solve(col+1,board,res,n,left, upperDiagnonal,lowerDiagnonal);
                left[row] = false;
                lowerDiagnonal[row+col] = false;
                upperDiagnonal[n-1+row-col] =false;
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> res;
        vector<bool> left(n,false);
        vector<bool> upperDiagnonal(2*n-1,false);
        vector<bool> lowerDiagnonal(2*n-1,false);
        string s(n,'.');
        for(int i=0;i<n;i++) {
            board[i]=s;
        }
        solve(0,board,res,n, left, upperDiagnonal,lowerDiagnonal);
        return res;

    }
};