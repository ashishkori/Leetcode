class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> count(501,0);
        for(auto x:arr){
            count[x]++;
        }
        int res=-1;
        for(int i=1;i<501;i++) {
            if(i==count[i]) res=i;
        }
        return res;
    }
};