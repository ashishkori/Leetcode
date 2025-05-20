class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_set<char> st;
        if(s.length() != t.length()) return false;
        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i]) == mp.end() && st.find(t[i]) == st.end()){
                mp[s[i]] = t[i];
                st.insert(t[i]);
            } else {
                if(mp.find(s[i]) == mp.end()) return false;
                if(mp[s[i]] != t[i]) return false;
            }
        }
        return true;

        /*
        unordered_map<char, char> m1;
        unordered_set<char> s1;
        if(s.length() != t.length()) return false;
        for(int i=0; i<s.length(); i++){
            if(m1.find(s[i]) == m1.end()){
                if(s1.find(t[i]) !=  s1.end()) return false;
                m1[s[i]] = t[i];
                s1.insert(t[i]);
            } else{
                if(m1[s[i]] != t[i]) return false;
            }
        }
        return true;*/
    }
};