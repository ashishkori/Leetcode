class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto x:words) {
            if(equal(x.begin(),x.end(),x.rbegin())) return x;
           // if(x==tmp) return x;
        }
        return "";
    }
};