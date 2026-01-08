class Solution {
public:
    vector<int> parrent;
    vector<int> rank;
    int Find(int x, vector<int>&parrent) {
        if(x== parrent[x]) return x;
        return parrent[x] = Find(parrent[x],parrent);

    }
    void Union(int x, int y){
        int p_x = Find(x,parrent);
        int p_y = Find(y,parrent);
        if(p_x==p_y) return;
        if(rank[p_x]>rank[p_y]) {
            parrent[p_y]=p_x;
        } else if(rank[p_x]<rank[p_y]) {
            parrent[p_x]=p_y;
        } else {
             parrent[p_x]=p_y;
             rank[p_x]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        parrent.resize(n,0);
        rank.resize(n);
        for(int i=0;i<n;i++) {
            parrent[i]=i;
        }
        int component=n;
        for(auto &x:connections) {
            int u =x[0];
            int v = x[1];
            if(Find(u, parrent)!=Find(v,parrent)) {
                component--;
                Union(u,v);
            }
        }
        return component-1;
    }
};