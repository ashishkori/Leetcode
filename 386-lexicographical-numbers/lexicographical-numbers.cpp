class Solution {
public:
    void solve(vector<int>& res, int i, int n) {
        if(i>n) return;
        res.push_back(i);
        for(int j=0;j<=9;j++) {
            int newN=i*10+j;
            if(newN>n) return;
            solve(res,newN,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1;i<=9;i++) {
            solve(res,i,n);
        }
        return res;
    }
};