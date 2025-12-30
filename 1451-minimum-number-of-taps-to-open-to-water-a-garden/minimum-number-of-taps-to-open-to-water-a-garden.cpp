class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> cover(n+1);
        for(int i=0;i<=n;i++) {
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            cover[start]=max(end,cover[start]);
        }
        int taps=0;
        int maxEnd=0;
        int curr=0;

        for(int i=0;i<=n;i++) {
            if(i>maxEnd) return -1;
            if(i>curr) {
                taps++;
                curr=maxEnd; 
            }
            maxEnd=max(maxEnd,cover[i]);
        }

        return taps;
    }
};