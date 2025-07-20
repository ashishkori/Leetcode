class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int min=*max_element(weights.begin(),weights.end());
        int max = std::accumulate(weights.begin(),weights.end(),0);
        while(min<=max) {
            int mid=min+(max-min)/2;
            if(capacity(weights, mid)<=days) max=mid-1;
            else min=mid+1;
        }
        return min;
    }
private:
    int capacity(vector<int>&wt, int m) {
        int days=0;
        int count=0;
        for(auto x:wt) {
            if(count+x<=m) {
                count+=x;
            } else {
                ++days;
                count=x;
            }
        }
        if(count) ++days;
        return days;
    }
};