class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string>st(bank.begin(),bank.end());
        set<string> visited;
        queue<string> qu;
        qu.push(start);
        int level=0;
        while(!qu.empty()) {
            int n=qu.size();
            while(n--) {
            string curr=qu.front();
            qu.pop();
            if(curr==end) return level;
            for(char s:"ATCG") {
                for(int i=0;i<curr.size();i++) {
                    string tmp=curr;
                    tmp[i]=s;
                    if(visited.find(tmp)==visited.end() && st.find(tmp)!=st.end()) {
                        visited.insert(tmp);
                        qu.push(tmp);
                    }
                }
            }

            }
            level++;
        }

        return -1;
    }
};