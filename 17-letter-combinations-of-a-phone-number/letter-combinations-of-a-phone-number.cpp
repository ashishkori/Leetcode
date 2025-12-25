class Solution {
public:
    vector<string> st={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n;
    void solve(int idx,string s, vector<string>& res, string& curr){
        if(idx>=n) {
            res.push_back(curr);
            return;
        }
        char ch=s[idx];
        string s1=st[ch-'2'];
        for(int i=0; i<s1.size();i++) {
            curr.push_back(s1[i]);
            solve(idx+1, s, res, curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n=digits.size();
        if(n==0) return {""};
        vector<string> res;
        string curr="";
        solve(0,digits,res,curr);
        return res;
        
    }
};