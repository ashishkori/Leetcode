class Solution {
public:
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x:nums) mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(auto &x:mp) {
            pq.push({x.second,x.first});
        }
        vector<int> res;
        while(k>0 && !pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
    vector<int> topKFrequent1(vector<int>& nums, int k) { 
        unordered_map<int,int>mp;
        for(auto x:nums) mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(auto &x:mp) {
            pq.push({x.second,x.first});
        }
        vector<vector<int>> bucket(nums.size()+1);
        vector<int> res;
         for(auto &x:mp) {
            bucket[x.second].push_back(x.first);
        }
        for(int i=bucket.size()-1;i>=0;i--) {
            if(!bucket[i].empty()) {
                if(res.size()==k) {
                        break;
                }
                for(auto x:bucket[i])  {
                    if(res.size()==k) {
                        break;
                    } else {
                        res.push_back(x);
                    }
                }
            }
        }
        return res;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) { 
        return 0?topKFrequent2(nums,k):topKFrequent1(nums,k);
     }
};