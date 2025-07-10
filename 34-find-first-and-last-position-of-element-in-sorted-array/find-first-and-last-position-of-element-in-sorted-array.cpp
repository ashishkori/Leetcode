class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int mid = -1;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid]==target) break;
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        int start = mid, end = mid;
        if (l>r) {
            start = -1;
            end =-1;
        } else {
            while(start >0 && nums[start]==nums[start-1]) start--;
            while(end<nums.size()-1 && nums[end]==nums[end+1]) end++;
        }
        vector<int> res = {start,end};
        return res;
    }
};