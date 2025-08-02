class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> result;
         sort(intervals.begin(),intervals.end());
         result.push_back(intervals[0]);
         for(int i=1;i<intervals.size();i++){
           // vector<int> curr=intervals[i];
            //int last=result.back()[1];
            if(result.back()[1]>=intervals[i][0]) {
                result.back()[1]=max(intervals[i][1],result.back()[1]);
            } else {
                result.push_back(intervals[i]);
            }
         }
         return result;
    }
};