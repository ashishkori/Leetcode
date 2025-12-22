class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int xr=0;
    for(auto x:nums) {
        xr^=x;
    }
    int mask=(1<<maximumBit)-1;
    vector<int> res;
    int n=nums.size();
    for(int i=0;i<nums.size();i++) {
        res.push_back(xr^mask);
        xr^=nums[n-i-1];
    }
    return res;
    }
};