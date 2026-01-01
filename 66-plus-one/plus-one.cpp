class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;
        int i=n-1;
        while(carry && i>=0) {
            int num=digits[i]+carry;
            digits[i]=num%10;
            carry=num/10;
            i--;
        }
        vector<int> res;
        if(carry) res.push_back(carry);
        for(auto x:digits) res.push_back(x);
        return res;
    }
};