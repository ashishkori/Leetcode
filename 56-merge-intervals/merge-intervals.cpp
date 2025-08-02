class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> result;
         sort(intervals.begin(),intervals.end());
         result.push_back(intervals[0]);
         for(int i=1;i<intervals.size();i++){
            vector<int> curr=intervals[i];
            int last=result.back()[1];
            if(last>=curr[0]) {
               // int start = result.back()[0];
                //result.pop_back();
                result.back()[1]=max(curr[1],last);
            } else {
                result.push_back(curr);
            }
         }
         return result;
    }
};