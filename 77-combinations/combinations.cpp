class Solution {
public:
    void solve(int idx, int n, int k, vector<vector<int>>& res, vector<int>& curr){
        if(k==0) {
            res.push_back(curr);
            return;
        }
        if(idx>n) return;
        curr.push_back(idx);
        solve(idx+1,n,k-1,res,curr);
        curr.pop_back();
        solve(idx+1,n,k,res,curr);
    }

    vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> curr;
    solve(1,n,k,res,curr);
    return res;
    }
};