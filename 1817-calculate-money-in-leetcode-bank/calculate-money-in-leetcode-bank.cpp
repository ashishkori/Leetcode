class Solution {
public:
    int totalMoney(int n) {
        long long w = n / 7;
        long long r = n % 7;
        
        long long S_weeks = 7LL * w * (w + 7) / 2; 
        
        long long start = w + 1;
        long long S_rem = r * (2 * start + (r - 1)) / 2;
        
        long long total = S_weeks + S_rem;
        return (int) total;
    }
};