class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>mp;
        priority_queue<int> pq;
        for(char ch:tasks) {
            mp[ch]++;
        }
        for(auto &x:mp) {
            pq.push(x.second);
        }
        int res=0;
       // if(n==1) return tasks.size();
        while(!pq.empty()) {
            vector<int> tmp;
            for(int i=1;i<=n+1;i++) {
                if(!pq.empty()) {
                    int freq=pq.top();
                    freq--;
                    pq.pop();
                    tmp.push_back(freq);
                }
            }
            for(auto x:tmp) {
                if(x>0) pq.push(x);
            }
            if(pq.empty()) {
                res+=tmp.size();
            } else {
                res+=n+1;
            }
        }
        return res;
    }
};