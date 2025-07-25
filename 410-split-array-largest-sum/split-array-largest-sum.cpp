class Solution {
public:
    int solve(vector<int>&arr,int sum) {
        int count=1;
        int ls=0;
        for(auto x:arr) {
            if(ls+x>sum){
                ++count;
                ls=x;
            } else {
                ls+=x;
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int h = accumulate(nums.begin(),nums.end(),0);
        while(l<=h) {
            int mid = l+(h-l)/2;
            (solve(nums,mid)>k)?l=mid+1:h=mid-1;
        }
        return l;
    }
};