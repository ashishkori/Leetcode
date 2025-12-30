class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k;
        int j=k;
        int res=nums[k];
        int mini=nums[k];
        int n=nums.size();
        while(i>0 || j<n-1) {
            int l=i>0?nums[i-1]:0;
            int r=j<n-1?nums[j+1]:0;
            if(l>r) {
                i--;
                mini=min(mini,nums[i]);
            } else {
                j++;
                mini=min(mini,nums[j]);
            }

            res=max(res,mini*(j-i+1));
        }
        return res;
    }
};