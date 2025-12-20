class Solution {
public:
    void solve(map<int,int>& mp,vector<vector<int>>& res, vector<int>& tmp, int n) {
        if(tmp.size()==n) {
            res.push_back(tmp);
            return;
        }
        for(auto[num,count]:mp) {
            if(count==0) continue;
            tmp.push_back(num);
            mp[num]--;
            solve(mp,res,tmp,n);
            mp[num]++;
            tmp.pop_back();
        }
    }
    void solve1(vector<int>& nums,vector<vector<int>>& res, int idx){
        if(idx==nums.size()) {
            res.push_back(nums);
            return;
        }
        set<int> st;
        for(int i=idx;i<nums.size();i++) {
            if(st.find(nums[i])!=st.end()) continue;
            st.insert(nums[i]);
            swap(nums[idx],nums[i]);
            solve1(nums,res,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int> mp;
        vector<vector<int>> res;
        vector<int>tmp;
        for(auto x:nums) {
            mp[x]++;
        }
        0?solve(mp,res,tmp, nums.size()):solve1(nums,res,0);
        return res;
    }
};