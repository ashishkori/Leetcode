class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        set<char> prefix, sufix;
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        for(int i=0;i<n;i++) {
            prefix.insert(s[i]);
            sufix.insert(s[n-1-i]);
            pre[i]=prefix.size();
            suf[n-1-i]=sufix.size();
        }
        int count =0;
        for(int i=0;i<n-1;i++) {
            if(pre[i]==suf[i+1]) count++;
        }
        return count;
    }
};