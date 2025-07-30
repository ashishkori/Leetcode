class Solution {
public:
    int jump(vector<int>& nums) {
    int farthest =0, curr = 0, jump =0;
    for (int i=0;i<nums.size()-1;i++) {
        farthest = max(farthest,nums[i]+i);
        if(i==curr) { 
            curr = farthest;
            jump++;
        }   
    }
    return jump;
    }
};