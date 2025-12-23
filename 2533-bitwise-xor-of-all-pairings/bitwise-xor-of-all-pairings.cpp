class Solution {
public:
    int xorAllNums2(vector<int>& nums1, vector<int>& nums2) { 
       int m=nums1.size();
       int n=nums2.size();
       int res=0;
       
       if(n&1) {
            for(auto x:nums1) res=res^x;
       }
        if(m&1) {
             for(auto x:nums2) res=res^x;
       }
       return res;
    }
    int xorAllNums1(vector<int>& nums1, vector<int>& nums2) {
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

     int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        return 0?xorAllNums1(nums1, nums2):xorAllNums2(nums1,nums2);
     }
};