class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(nums.begin(), nums.end());
        int res=0;
        while(pq.size()>1) {
            if(pq.top()>=k) break;
            long x=pq.top();pq.pop();
            long y=pq.top();pq.pop();
            long newNum=min(x,y)*2+(max(x,y));
            pq.push(newNum);
            res++;
        }
        return res;

    }
};