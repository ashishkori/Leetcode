class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0;
        string words="";
        string res="";
        while(i<s.size()) {
            if(s[i] == ' ') { 
                if(words.size()>0) {
                reverse(words.begin(),words.end());
                res = res + " " + words;
                words="";
            }
            } else {
                words+=s[i];
            }
            i++;
        }
        if(words.size()>0) {
                reverse(words.begin(),words.end());
                res = res + " " + words;
        }
    if(res.size()) return res.substr(1);
        return res;
}
};