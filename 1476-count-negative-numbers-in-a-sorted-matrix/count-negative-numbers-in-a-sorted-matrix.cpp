class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(auto x:grid) {
            for(auto n:x) if(n<0) count++;
        }

        return count;
    }
};