class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReadIndx=0;
        for(int i=0;i<nums.size();i++) {
            if(i>maxReadIndx) return false;
            else {
                maxReadIndx=max(maxReadIndx,i+nums[i]);
            }
        }
        return true;

    }
};