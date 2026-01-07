class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        int i=0,j=mp[s[0]];
        int start=0;
        int count=0;
        vector<int> res;
        while(i<s.size()) {
            if(i>j) {
                res.push_back(i-start);
                start=i;
               //count=0;
            }
            count++;
            j=max(j,mp[s[i]]);
            i++;
        }
        if(start<i) res.push_back(i-start); 
        return res;
    }
};