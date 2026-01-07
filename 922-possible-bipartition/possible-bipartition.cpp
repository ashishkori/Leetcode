class Solution {
public:
    bool bfs(int idx, map<int,vector<int>>& mp, vector<int>& color) {
        queue<int> qu;
        qu.push(idx);
        color[idx]=1;
        while(!qu.empty()) {
            int u=qu.front();
            qu.pop();
            for(auto v:mp[u]) {
                if(color[u]==color[v]) return false;
                if(color[v]==-1) {
                    qu.push(v);
                    color[v]=1-color[u];
                }              
            }
            
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        map<int,vector<int>>mp;
        for(auto &x:dislikes) {
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        vector<int> color(n+1,-1);
        for(int i=0;i<n;i++) {
            if(color[i]==-1) {
                if(!bfs(i,mp,color)) return false;
            }
        }
        return true;       
    }
};