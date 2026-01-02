class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    struct lambda {
        bool operator()(P& p1, P& p2){
            return p1.first>p2.first;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<P,vector<P>, lambda> pq;
    int m=nums1.size();
    int n=nums2.size();
    vector<vector<int>> res;
    set<pair<int,int>>visisted;
    pq.push({nums1[0]+nums1[0],{0,0}});
    visisted.insert({0,0});
   
    while(k>0 && !pq.empty()) {
        auto tmp=pq.top();
        pq.pop();
        int i=tmp.second.first;
        int j=tmp.second.second;
        res.push_back({nums1[i], nums2[j]});
        if(j+1<n && visisted.find({i,j+1})==visisted.end()) {
            pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            visisted.insert({i,j+1});
        }
        if(i+1<m && visisted.find({i+1,j})==visisted.end()){
            pq.push({nums1[i+1]+nums2[j],{i+1,j}});
            visisted.insert({i+1,j});
        }
 
        k--;
        }
    return res;
    }
    
};