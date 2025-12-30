class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();

        vector<int> time(n,0);
        for(int i=0;i<n;i++){
            time[i]=ceil((float)dist[i]/speed[i]);
        }
        sort(time.begin(),time.end());
        int count=1;
        int t=1;
        for(int i=1;i<n;i++) {
            if(time[i]-t<=0) { 
                return count;
            }
            count++;
            t++;
        }
        return count;
    }
};