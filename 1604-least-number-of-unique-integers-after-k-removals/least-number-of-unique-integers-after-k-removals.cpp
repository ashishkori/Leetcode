class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto x:arr) mp[x]++;
        vector<int> freq;
        for(auto x:mp) {
            freq.push_back(x.second);
        }
        int count=0;
        sort(freq.begin(),freq.end());
        for(auto x:freq) {
            if(x<=k){
                k-=x;
                count++;
            } else {
                break;
            }

        }
        return freq.size()-count;
    }
};