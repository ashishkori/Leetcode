class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> result;
         vector<int> tmp;
         backtrack(nums, result, tmp, 0,nums.size());
         return result;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>&tmp, int index, int n) {
    
        result.push_back(tmp);
        
        for(int i=index; i<n; i++){ 
            tmp.push_back(nums[i]);
            backtrack(nums,result,tmp,i+1,n);
            tmp.pop_back();
        }

    }    
};