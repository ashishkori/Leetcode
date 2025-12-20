class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, int i, vector<int>&tmp) {
        if(i==nums.size()) {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(nums[i]);
        solve(nums,res,i+1,tmp);
        tmp.pop_back();
        solve(nums,res,i+1,tmp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> tmp;
      solve(nums,res,0,tmp);
      return res;  
    }
};