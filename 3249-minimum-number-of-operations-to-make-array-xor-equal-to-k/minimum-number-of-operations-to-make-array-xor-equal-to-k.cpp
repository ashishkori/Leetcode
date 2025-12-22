class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res=0;
        for(auto x:nums) {
            res^=x;
        }
        res^=k;
        int count=0;
        while(res) {
            res&=(res-1);
            count++;
        }
        return count;
    }
};