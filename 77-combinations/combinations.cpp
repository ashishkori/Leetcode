class Solution {
public:
    void solve1(int idx, int n, int k, vector<vector<int>>& res, vector<int>& curr){
        if(k==0) {
            res.push_back(curr);
            return;
        }
        if(idx>n) return;
        curr.push_back(idx);
        solve1(idx+1,n,k-1,res,curr);
        curr.pop_back();
        solve1(idx+1,n,k,res,curr);
    }
    void solve2(int idx, int n, int k, vector<vector<int>>& res, vector<int>& curr){
        if(k==0) {
            res.push_back(curr);
            return;
        }
    
        for(int i=idx;i<=n;i++) {
            curr.push_back(i);
            solve2(i+1,n,k-1,res,curr);
            curr.pop_back();
        }
        //solve(idx+1,n,k,res,curr);
    }

    vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> curr;
    0?solve1(1,n,k,res,curr):solve2(1,n,k,res,curr);
    return res;
    }
};