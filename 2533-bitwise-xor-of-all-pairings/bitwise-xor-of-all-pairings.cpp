class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
       map<int,long>mp;
       int m=nums1.size();
       int n=nums2.size();
       for(auto x:nums1) {
            mp[x]+=n;
       } 
       for(auto x:nums2) {
            mp[x]+=m;
       }
       int res=0;
       for(auto [x,y]:mp) {
            if(y%2) res^=x;
       } 
       return res;
    }
};