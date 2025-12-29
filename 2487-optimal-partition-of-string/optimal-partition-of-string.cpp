class Solution {
public:
    int partitionString(string s) {
        map<char,int>mp;
        int count=1;
        for(int i=0;i<s.size();i++) {
            char ch=s[i];
            if(mp.find(ch)!=mp.end()) {
                count++;
                mp.clear();
                mp[ch]=i;
            } else {
                 mp[ch]=i;
            }
        }
        return count;
    }
};