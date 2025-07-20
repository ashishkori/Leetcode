class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int min = 1;
        int max = *max_element(nums.begin(),nums.end());
        if(nums.size()==threshold) return max;
        while(min<=max) {
            int mid=(min+max)/2;
            if(div(nums,mid)<=threshold) max=mid-1;
            else min=mid+1;
        }
        return min;
    }
private:
    int div(vector<int>& nums, int k) {
        int count=0;
        for(auto x:nums) {
            count+=x/k;
            if(x%k) count++;
        }
        return count;
    }
};