class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n =s.size();
        int i=0;
        for(auto x:t) {
            if(x==s[i]) i++;
        }
        return i==n;
    }
};