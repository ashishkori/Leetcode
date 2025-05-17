class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int flag = 0;
        for(int i=nums.size()-2; i>=0; --i)
        {
            if(nums[i]<nums[i+1])
            {
                flag = 1;
                for(;(i+flag+1)<nums.size() && nums[i+flag+1]>nums[i]; ++flag);
                int tmp = nums[i];
                nums[i] = nums[i+flag];
                nums[i+flag] = tmp;

                sort(nums.begin()+i+1, nums.end());
                break;
            }
        }
        if(flag==0)
        {
            sort(nums.begin(), nums.end());
        }
    }
};