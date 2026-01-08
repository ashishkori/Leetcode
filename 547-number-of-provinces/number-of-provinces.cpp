class Solution {
public:
    void dfs(map<int,vector<int>>& mp, int s, vector<bool>& visit){
        visit[s]=true;
        for(auto &v:mp[s]){
            if(!visit[v]) dfs(mp,v,visit);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        map<int,vector<int>> mp;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]) {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<bool> visit(n,false);
        for(int i=0;i<isConnected.size();i++) {
            if(!visit[i]){
                count++;
                dfs(mp,i,visit);
            }
        }
        return count;
    }
};