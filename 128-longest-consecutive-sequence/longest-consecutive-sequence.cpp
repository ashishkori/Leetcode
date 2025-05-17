class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto x:nums) set.insert(x);
        int longest=0;
        for(auto st:set) {
            if(set.find(st-1)==set.end()) {
                int start = st;
                int count=0;
                while(set.find(start) !=set.end()) {
                    start++;
                    count++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};