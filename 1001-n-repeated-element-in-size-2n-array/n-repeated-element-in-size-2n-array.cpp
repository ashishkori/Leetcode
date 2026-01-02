class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &x:nums) {
            if(st.find(x)!=st.end()) return x;
            st.insert(x);
        }
        return -1;
    }
};