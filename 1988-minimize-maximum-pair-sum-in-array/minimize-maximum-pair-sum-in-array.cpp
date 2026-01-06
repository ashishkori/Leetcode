class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        int res=INT_MIN;
        while(l<r) {
            res=max(res,nums[l++]+nums[r--]);
        }
        return res;
    }
};