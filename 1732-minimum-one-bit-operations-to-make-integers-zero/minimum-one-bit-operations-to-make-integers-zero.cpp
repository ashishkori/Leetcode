class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<long> F(32,0);
        F[0]=1;
        for(int i=1;i<32;i++) {
            F[i]=2*F[i-1]+1;
        }
        int sign=1;
        long res=0;
        for(int i=31;i>=0;i--) {
            if((n&(1<<i))) {
                res+=(sign * F[i]);
                sign*=-1;
            }
         }
         return res;
    }
};