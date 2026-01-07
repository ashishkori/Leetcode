class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> qu;
        qu.push(0);
        vector<bool> visit(rooms.size(),false);
        visit[0] = true;
        while(!qu.empty()) {
            int idx=qu.front();
            qu.pop();
            for(auto x:rooms[idx]) {
                if(!visit[x]){
                    qu.push(x);
                    visit[x]=true;
                }
            }
        }
        for(int i=0;i<visit.size();i++) {
            if(!visit[i]) return false;
        }
        return true;
    }
};