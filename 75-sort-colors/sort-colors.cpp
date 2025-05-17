class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countz=0,counto=0;
        for(auto x:nums) {
            if(x==0) countz++;
            else if(x==1) counto++;
            else continue;
        }
        int i=0;
        for(;i<countz;i++){
            nums[i]=0;
        }
        for(;i<countz+counto;i++){
            nums[i]=1;
        }
        for(;i<nums.size();i++){
            nums[i]=2;
        }
    }
};