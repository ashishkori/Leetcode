class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx=s.find_last_not_of(" ")+1;
       // int idx = s.find_last_not_of(" ") +1;
        s.erase(idx);
        int st=s.find_last_of(" ");
        return st==string::npos?s.size():s.size()-st-1;
    }
};