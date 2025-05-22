class Solution {
public:
    string reorganizeString(string s) {
        vector<int> hash(26,0);
        int max=0;
        char ch;
        for(char x:s) {
            hash[x-'a']++;
            if(hash[x-'a']>=max) {
                max = hash[x-'a'];
                ch=x;
            }
        }
        if (2*max-1>s.size()) return "";
        int idx=0;
        vector<char> res(s.size());
        for(int i=0;i<hash[ch-'a'];i++) {
            res[idx]=ch;
            idx+=2;
        }
        hash[ch-'a']=0;
        for(int i=0;i<26;i++) {
            while(hash[i]!=0) {
            if(idx>=s.size()) idx=1;
                res[idx]='a'+i;
                hash[i]--;
                idx+=2;
            }
        }
        string result(res.begin(),res.end());
        return result;
    }
};