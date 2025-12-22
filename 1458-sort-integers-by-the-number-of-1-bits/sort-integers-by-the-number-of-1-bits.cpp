class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
       auto lambda = [](int a, int b) {
            int xc=__builtin_popcount(a);
            int yc=__builtin_popcount(b);
            if(xc==yc) return a<b;

            return xc<yc;
        };
        sort(arr.begin(),arr.end(),lambda);
        return arr;
    }
};