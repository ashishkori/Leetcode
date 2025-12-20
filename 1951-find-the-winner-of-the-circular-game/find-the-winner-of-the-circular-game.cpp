class Solution {
public:
    int findTheWin(int n, int k) {
        if(n==1) {
            return 0;
        }
        int idx=findTheWin(n-1,k);
        idx=(idx+k)%n;
        
        return idx;
    }
     int findTheWinner(int n, int k) { 
        return (findTheWin(n,k)+1);
     }
};