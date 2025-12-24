class Solution {
public:
    int maximumCount1(vector<int>& nums) {
        auto lambdaP = [](int a) {
            return a>0;
        };
        auto lambdaN = [](int a) {
            return a<0;
        };
        int c = count_if(nums.begin(),nums.end(),lambdaP);
        int c1 = count_if(nums.begin(),nums.end(),lambdaN);
        return max(c,c1);
        }
        int maximumCount2(vector<int>& nums) {
            int n=nums.size();
            int po = nums.end()- lower_bound(nums.begin(),nums.end(),1);
            int ne = lower_bound(nums.begin(),nums.end(),0)-nums.begin();
            return max(po,ne);
        }
        int maximumCount(vector<int>& nums) { 
            return 0?maximumCount1(nums):maximumCount2(nums);
        }
};