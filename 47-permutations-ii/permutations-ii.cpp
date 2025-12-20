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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int> mp;
        vector<vector<int>> res;
        vector<int>tmp;
        for(auto x:nums) {
            mp[x]++;
        }
        solve(mp,res,tmp, nums.size());
        return res;
    }
};