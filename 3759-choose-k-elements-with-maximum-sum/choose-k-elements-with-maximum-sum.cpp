class Solution {
public:
    typedef pair<int,pair<int,int>>PP;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n=nums1.size();
        vector<PP> vec(n);
        for(int i=0;i<n;i++) {
            vec[i]={nums1[i],{i,nums2[i]}};
        }
       // int res=0;
        sort(vec.begin(),vec.end());
        
        priority_queue<int, vector<int>,greater<int>> pq;
        vector<long long> res(n,0);
       // if(vec[0].first==vec[n-1].first) return res;
        long long sum=0;
        for(int i=0;i<n;i++) {
            int val1=vec[i].first;
            int idx=vec[i].second.first;
            int val2=vec[i].second.second;
            if(i>0 && vec[i].first == vec[i-1].first) {
                res[idx]=res[vec[i-1].second.first];
                //continue;
            } else {
                 res[idx]=sum;
            }

            sum+=val2;
            pq.push(val2);
            if(pq.size()>k) {
                sum-=pq.top();
                pq.pop();
            }
        }
        return res;
    }
};