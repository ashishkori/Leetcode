class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums) {
            if(mp[x]==0) mp[x]++;
            else return x;
        }
        return -1;
    }
};