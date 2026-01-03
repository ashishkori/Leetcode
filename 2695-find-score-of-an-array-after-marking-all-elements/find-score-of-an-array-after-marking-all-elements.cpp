class Solution {
public:
    typedef pair<int,int> P;
    struct lambda{
        bool operator()(P& p1, P& p2){
            if(p1.first== p2.first) return p1.second>p2.second;
            return p1.first>p2.first;
        }
    };
    long long findScore(vector<int>& nums) {
        long long res=0;
        priority_queue<P,vector<P>,lambda> pq;
        for(int i=0;i<nums.size();i++) {
            pq.push({nums[i],i});
        }
        vector<bool> visited(nums.size(),false);
        int n=nums.size();
        while(!pq.empty()) {
            auto x=pq.top();
            int ind=x.second;
            pq.pop();
          //  cout<< "processing ind "<<ind<<" Value "<<x.first<<endl;
            if(visited[ind] == false) {
                visited[ind]=true;
                res+=x.first;
                //cout<< "processing ind "<<ind<<" Value "<<x.first<<endl;
                if(ind<n-1) visited[ind+1] = true;
                if(ind>=1) visited[ind-1] = true;
            } 
            
        }
        return res;
    }
};