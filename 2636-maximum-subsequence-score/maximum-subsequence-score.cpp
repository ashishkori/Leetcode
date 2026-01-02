class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> vec;
        for(int i=0;i<nums1.size();i++) {
            vec.push_back({nums1[i],nums2[i]});
        }
        sort(vec.begin(),vec.end(),[](pair<int,int>& p1, pair<int,int>p2){
            return p1.second>p2.second;
        });
        int n=vec.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int idx=0;
        long long sum=0;
        long long res=INT_MIN;
        while(idx<k) {
            pq.push(vec[idx].first);
            sum+=vec[idx].first;
            idx++;
        }
        res=max(res,sum*vec[k-1].second);
        for(int idx = k; idx<n;idx++) {
            sum+=vec[idx].first-pq.top();
            pq.pop();
            pq.push(vec[idx].first);
            res=max(res,sum*vec[idx].second);
        }

        return res;
    }
};