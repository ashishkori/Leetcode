class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row=0;
        auto lambda = [&](int sum, vector<int> vec) {
            sum+=vec[row];
            if(row!=(vec.size()-row-1)) sum+=vec[vec.size()-row-1];
            row++;
            return sum;
        };
        return accumulate(mat.begin(),mat.end(),0,lambda);
    }
};