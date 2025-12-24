class Solution {
public:
    bool isPossible(vector<int> nums, int n, long long l) {
        long long reqM=n*l;
        for(auto x:nums) {
            reqM-=min(l,(long long) x);
            if(reqM<=0) return true;
        }

        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
       long long l=*min_element(batteries.begin(),batteries.end());
       unsigned long long sum = 0;
       for(auto x:batteries) sum+=x;
       long long r=sum/n;
       while(l<=r) {
        long long mid=l+(r-l)/2;
        if(isPossible(batteries,n,mid)) {
            l=mid+1;
        } else {
            r=mid-1;
        }
        }
        return r;
    }
};