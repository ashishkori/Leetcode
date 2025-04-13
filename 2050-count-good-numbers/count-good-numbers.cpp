class Solution {
public:
    const int MOD = 1e9 + 7;
    long long countP(long long n, long long  pow) {
        long res=1;
        while(pow) {
            if(pow%2) {
                res=(res*n)%MOD;
            }
            n=n*n%MOD;
            pow/=2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long odd =n/2;
        long long even = n-odd;
        return countP(5,even)*countP(4,odd)%MOD;

    }
};