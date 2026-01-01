class Solution {
public:
    typedef pair<int,int> P;
    // struct lambda{
    //     bool operator()(P& p1, P& p2){
    //         return p1.second < p2.second;
    //     }
    // };
    vector<int> getOrder(vector<vector<int>>& tasks) {
       // priority_queue<P,vector<P>,lambda>pq;
        vector<vector<int>> sortedTask;
        for(int i=0;i<tasks.size();i++) {
            sortedTask.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(sortedTask.begin(),sortedTask.end());
        priority_queue<P,vector<P>,greater<>> pq;
        int n=sortedTask.size();
        long long start_time=0;
        int idx=0;
        vector<int> res;
        while(idx<n || !pq.empty()) {
            if(pq.empty() && start_time<sortedTask[idx][0]) {
                start_time = sortedTask[idx][0];
            }
            while(idx<n && sortedTask[idx][0]<=start_time) {
                pq.push({sortedTask[idx][1],sortedTask[idx][2]});
                idx++;
            }
            
            int duration=pq.top().first;
            res.push_back(pq.top().second);
            pq.pop();
            start_time+=duration;

        }
        return res;
    }
};