class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<vector<int>>& res, vector<int>& curr) {
        if(curr.size()>=2) {
            res.push_back(curr);
        }
        set<int> st;
        for(int i=idx;i<nums.size();i++) {
            if((curr.empty() || nums[i]>=curr.back()) && st.find(nums[i])==st.end()) {
                curr.push_back(nums[i]);
                solve(nums,i+1,res,curr);
                curr.pop_back();
            }
            st.insert(nums[i]);
        }

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(nums,0,res,curr);
        return res;
    }
};