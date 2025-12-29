class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mp;
        int count=0;
        int last=-1;
        for(int i=0;i<s.size();i++) {
            char ch=s[i];
            if(mp.find(ch) !=mp.end()) { 
                if(mp[ch]>=last) {
                last=i;
                count++;
                }
            }
            mp[ch]=i;
        }
        return count+1;
    }
};