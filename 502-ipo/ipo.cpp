class Solution {
public:
    typedef pair<int,int> P;
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<P> vec;
        for(int i=0;i<profits.size();i++) {
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end());
        int i=0;
        int n=vec.size();
        priority_queue<int> pq;
       // int res=0;
        while(k--) {
            while(i<n && vec[i].first<=w) {
                pq.push(vec[i].second);
                i++;
            }
            if(pq.empty()) break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};