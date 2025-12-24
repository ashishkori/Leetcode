class Solution {
public:
    int n;
    int res;
    void solve(int idx, vector<int>& cookies, vector<int>& child, int k) {
        if(idx>=n) {
            int mx=*max_element(child.begin(),child.end());
            res=min(res,mx);
            return;
        }

        int cok=cookies[idx];
        for(int i=0;i<k;i++) {
            child[i]+=cok;
            solve(idx+1,cookies,child,k);
            child[i]-=cok;
        }

    }
    int distributeCookies(vector<int>& cookies, int k) {
        res=INT_MAX;
        n=cookies.size();
        vector<int> child(k,0);
        solve(0,cookies,child,k);
        return res;

    }
};