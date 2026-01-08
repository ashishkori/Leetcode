class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
       vector<int> indgree(n,0);
       map<int,vector<int>>mp;
       for(int i=0;i<pre.size();i++){
        auto &x=pre[i];
        int u=x[0];
        int v=x[1];
        mp[u].push_back(v);
        indgree[v]++;
       }
        int count=0;
       queue<int> qu;
       for(int i=0;i<n;i++) {
        if(indgree[i]==0) {
            qu.push(i);
            count++;
        }
       }
       while(!qu.empty()){
         int idx=qu.front();
         qu.pop();
         for(auto &v:mp[idx]) {
            indgree[v]--;
            if(indgree[v]==0) {
                qu.push(v);
                count++;
            }
         }
       }
       return count==n;
    }
};