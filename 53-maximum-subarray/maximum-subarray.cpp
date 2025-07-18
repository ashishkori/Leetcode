class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxL = 0;
        int maxS = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            maxL = max(maxL+nums[i],nums[i]);
            maxS = max(maxS,maxL);
        }
        return maxS;

    }
};