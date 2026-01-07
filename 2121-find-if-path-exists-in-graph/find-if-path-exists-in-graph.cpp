class Solution {
public:
    int dfs(unordered_map<int,vector<int>>& mp, int source, int destination,  vector<bool>& visited){
        if(source==destination) return true;
        if(visited[source]) return false;
        visited[source]=true;
        for(auto& vec:mp[source]) {
            if(dfs(mp, vec, destination, visited)) {
                return true;
            }
        }
        return false;
    }
    bool bfs(unordered_map<int,vector<int>>& mp, int source, int dest,  vector<bool>& visited) {
        queue<int> qu;
        qu.push(source);
        visited[source]=true;
        while(!qu.empty()){
            int n=qu.size();
            while(n) {
                int curr=qu.front();
                if(curr==dest) return true;
                qu.pop();
                for(auto& it:mp[curr]) {
                    if(!visited[it]) {
                        qu.push(it);
                        visited[it]=true;
                    }
                }
                n--;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool> visited(n,false);
        return 0?dfs(mp,source,destination,visited):bfs(mp,source,destination,visited);
    }
};