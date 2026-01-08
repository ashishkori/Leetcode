class Solution {
public:
    vector<int> parrent;
    vector<int> rank;
    int find(int x) {
        if(parrent[x]==x) return x;
        return parrent[x]=find(parrent[x]);
    }
    void Union(int x, int y) {
        int px=find(x);
        int py=find(y);
        if(px==py) return;
        if(rank[px==rank[py]]) {
            parrent[py]=px;
            rank[px]++;
        } else if (rank[px]>rank[py]) {
             parrent[py]=px;
        } else {
             parrent[px]=py;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        parrent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++) {
            parrent[i]=i;
        }
          for(int i=0;i<n;i++) {
            auto& s=equations[i];
            if(s[1]=='=') {
                Union(s[0]-'a',s[3]-'a');
            }
          }

           for(int i=0;i<n;i++) {
            auto& s=equations[i];
            if(s[1]=='!') {
                if(find(s[0]-'a')==find(s[3]-'a')) return false;
            }
          }
        return true;
    }
};