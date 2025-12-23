class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> setBitIndex(32, -1);
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            int lastIndex = i;
            int x = nums[i];
            for (int j = 0; j < 32; j++) {
                if (!(x & (1 << j))) {
                    if (setBitIndex[j] != -1) {
                        lastIndex = max(lastIndex, setBitIndex[j]);
                    }
                } else {
                    setBitIndex[j] = i;
                }
            }
            res[i]=(lastIndex-i+1);
        }
        return res;
    }
};