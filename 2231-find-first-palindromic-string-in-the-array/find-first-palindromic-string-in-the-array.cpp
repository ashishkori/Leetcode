class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto x:words) {
            int n=x.size();
            if(equal(x.begin(),x.begin()+n/2,x.rbegin())) return x;
           // if(x==tmp) return x;
        }
        return "";
    }
};