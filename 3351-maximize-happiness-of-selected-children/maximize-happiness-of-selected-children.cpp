class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long res=0;
        for(int i=0;i<k;i++) {
            long long hap=happiness[i]-i;
            if(hap<=0) break;
            res+=hap;
        }
        return res;
    }
};