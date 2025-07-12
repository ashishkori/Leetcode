class Solution {
public:
    bool rotateString(string s, string goal) {
        string newS = s+s;
        if(s.size()!=goal.size()) return false;
        return (newS.contains(goal));
    }
};