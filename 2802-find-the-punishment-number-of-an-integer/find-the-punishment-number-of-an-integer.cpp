class Solution {
public:
    bool solve(int sqnum, int curr_sum, int n) {
        if(sqnum==0) {
            return curr_sum==n;
        }
        return (solve(sqnum/10,curr_sum+sqnum%10,n) || solve(sqnum/100,curr_sum+sqnum%100,n) || solve(sqnum/1000,curr_sum+sqnum%1000,n)||solve(sqnum/10000,curr_sum+sqnum%10000,n));
    }
    int punishmentNumber(int n) {
        int count = 0;
        for(int i=1;i<=n;i++) {
            int sq=i*i;
            if(solve(sq,0,i)==true) {
                cout<<" i "<<i<<endl;
                count+=sq;
            }
        }
        return count;
    }
};