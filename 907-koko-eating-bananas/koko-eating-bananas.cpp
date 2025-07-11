class Solution {
public:
    unsigned int calH(vector<int>& piles, int h) {
        unsigned int res=0;
        for(auto x:piles) {
            res +=x/h;
            if(x%h) res++;
        }
        return res;
    } 
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r = *std::max_element(piles.begin(),piles.end());
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(calH(piles,mid)<=h) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};