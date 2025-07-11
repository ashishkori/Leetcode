class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        stringstream ss(s);
        string res;
        string word;
        while(ss >> word){
           reverse(word.begin(),word.end());
           res=res+" "+word;
        }
        return res.substr(1);
    }
};