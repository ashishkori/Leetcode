class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int xr=0;
    for(auto x:nums) {
        xr^=x;
    }
    int mask=(1<<maximumBit)-1;
    vector<int> res;
    for(int i=nums.size()-1;i>=0;i--) {
        res.push_back(xr^mask);
        xr^=nums[i];
    }
    return res;
    }
};