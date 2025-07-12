class Solution {
public:
    bool rotateString(string s, string goal) {
      //  string newS = s+s;
        //if(s.size()!=goal.size()) return false;
        return ( s.size()==goal.size() && (s+s).contains(goal));
    }
};