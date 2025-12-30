class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums) mp[x]++;
        int count=0;
        for(auto itr=mp.begin();itr!=mp.end();itr++) {
            int c=itr->second;
            if(c<=1) return -1;

            count+=(c/3);
            if(c%3 !=0) count++;
        }
        return count;
    }
};