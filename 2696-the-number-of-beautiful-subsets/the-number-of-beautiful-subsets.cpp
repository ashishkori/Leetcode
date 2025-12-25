class Solution {
public:
    int res=0;
    void solve(vector<int>& nums, int idx, int k, unordered_map<int,int>& mp) {
        if(idx>=nums.size()) {
            res++;
            return;
        }

        solve(nums,idx+1,k,mp);

        if(!mp[nums[idx]+k] && !mp[nums[idx]-k]) {
            mp[nums[idx]]++;
            solve(nums,idx+1,k,mp);
            mp[nums[idx]]--;
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        res=0;
        unordered_map<int,int> mp;
        solve(nums,0,k,mp);

        return res-1;


    }
};