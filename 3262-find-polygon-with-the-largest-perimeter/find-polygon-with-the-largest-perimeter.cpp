class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long res=-1;
        long long csum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++) {
            csum+=nums[i];
            if(i<1) continue;
            if(csum>nums[i+1]) res=csum+nums[i+1];
        }

        return res;
    }
};