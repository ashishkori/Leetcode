class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> count(101,0);
        for(auto x:nums) {
            count[x]++;
        }
        int sum=0;
        for(auto x:count) {
            if(x){
                sum+= (x*(x-1))/2;
            }
        }
        return sum;
    }
};