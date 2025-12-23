class Solution {
public:
    void update(vector<int> &vec, int num, int x) {
        for(int i=0;i<32;i++) {
            if(((num>>i)&1)==1) {
                vec[i]+=x;
            }
        }
    }
    int getNum(vector<int>& vec) {
        int n=0;
        for(int i=0;i<32;i++) {
            if(vec[i]>0) {
                n|=(1<<i);
            }
        }
        return n;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res=INT_MAX;
        int i=0, j=0;
        vector<int> vec(32,0);
        while(j<nums.size()) {
            update(vec,nums[j],1);
            while(i<=j && getNum(vec)>=k) {
                res=min(res,j-i+1);
                update(vec,nums[i],-1);
                i++;
            }
            j++;
        }
        return (res==INT_MAX)?-1:res;;
    }
};