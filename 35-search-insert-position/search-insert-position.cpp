class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid=-1;
        int l=0, r=nums.size() -1;

        while(l<=r) {
            mid = (l+r)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        return (nums[mid]<target)?mid+1:mid;
    }
};