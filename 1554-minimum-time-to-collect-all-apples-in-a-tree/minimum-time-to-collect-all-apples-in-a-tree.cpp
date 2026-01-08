class Solution {
public:
    int dfs(map<int,vector<int>>& mp,int source, int parent, vector<bool>& hasApple){
        int time=0;
        for(auto x:mp[source]){
            if(x==parent) continue;
            int t=dfs(mp,x,source,hasApple);
            if(t>0||hasApple[x]){
                time+=t+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        map<int,vector<int>> mp;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        return dfs(mp,0,-1,hasApple);
    }
};