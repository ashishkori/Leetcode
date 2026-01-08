class Solution {
public:
    vector<vector<int>> res;
    int n;
    void dfs(int source, vector<vector<int>>& mp,vector<int>& tmp) {
         tmp.push_back(source);
        if(source==n) {
            res.push_back(tmp);
            //return;
        } else { 
            for(auto &v:mp[source]) {
            dfs(v,mp,tmp);
            }
        }
        tmp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // map<int,vector<int>> mp;
        // for(int i=0;i<graph.size();i++){
        //     for(auto &v:graph[i]) {
        //         mp[i].push_back(v);
        //     }
        // }
        n=graph.size()-1;
        vector<int> tmp;
       // vector<bool> visit(mp.size(),false);
        dfs(0,graph,tmp);
        return res;
    }
};