class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int j=0;
        int m=target.size();
        for(int i=1;i<=n;i++){     
            res.push_back("Push");
            if(target[j]==i) {
                j++;
            } else {
                res.push_back("Pop");
            }
            if(j==m) break;
        }
        return res;
    }
};