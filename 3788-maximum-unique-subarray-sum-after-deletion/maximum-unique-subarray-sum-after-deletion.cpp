class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> count(101,0);
        if(nums.size()==1) return nums[0];
        int mx=INT_MIN;
        for(auto x:nums){
            if(x>0) count[x]=x;
            if(x>mx) mx=x;
        }
        int sum = accumulate(count.begin(),count.end(),0);
        return sum>0?sum:mx;
    }
};