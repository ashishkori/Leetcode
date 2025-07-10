class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l, int r) {
        while(l<=r) {
            int mid = (l+r)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,target,0,nums.size()-1);
    }
};