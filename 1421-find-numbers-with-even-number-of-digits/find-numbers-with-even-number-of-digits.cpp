class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto x:nums) {
            string i=to_string(x);
            if(i.size()%2==0) count++;
        }
        return count;
    }
};