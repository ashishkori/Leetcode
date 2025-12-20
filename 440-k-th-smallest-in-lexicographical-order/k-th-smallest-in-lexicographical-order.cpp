class Solution {
public:
    int count(long curr, long next, long n) {
       int c=0;
        while(curr<=n) {
            c+=next-curr;
            curr*=10;
            next*=10;
            next=min(next,n+1);
        }
        return c;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k>0){
            int co=count(curr,curr+1,n);
            if(co<=k){
                curr++;
                k-=co;
            } else {
                curr*=10;
                --k;
            }
        }
        return curr;
    }
};