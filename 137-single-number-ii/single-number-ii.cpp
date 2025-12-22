class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        int c1=0,c0=0;
        for(int i=0;i<(sizeof(int)*8);i++) {
            int c1=0,c0=0;
            for(auto x:nums) {
                if(x&(1<<i)) {
                    c1++;
                } else {
                    c0++;
                }
            }
            if(c1%3) res|=1<<i;
        }
        return res;
    }
};