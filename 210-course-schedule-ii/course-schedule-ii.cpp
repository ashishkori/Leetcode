class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n,0);
        vector<int> res;
        map<int,vector<int>> mp;
        queue<int> qu;
        for(auto &x:pre) {
            int u=x[0];
            int v=x[1];
            mp[u].push_back(v);
            indegree[v]++;
        }
        int count=0;
        for(int i=0;i<n;i++) {
            if(indegree[i]==0) {
                res.push_back(i);
                qu.push(i);
                count++;
            }
        }
        while(!qu.empty()) {
            int u=qu.front();
            qu.pop();
            for(auto &v:mp[u]) {
                indegree[v]--;
                if(indegree[v]==0) {
                    qu.push(v);
                    res.push_back(v);
                    count++;
                }
            }
        }
        reverse(res.begin(),res.end());
        return (count==n)?res:vector<int>();
    }
};