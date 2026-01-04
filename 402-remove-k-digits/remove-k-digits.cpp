class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        if(num.size()<=k) return "0";
        for(int i=0;i<num.size();i++) {
            char c=num[i];
            while(k>0 && !st.empty() && st.top()>c) {
                st.pop();
                k--;
            }
            st.push(c);
        }
       
        while(k>0 && !st.empty()) {
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        int i=0;
        while(i<res.size() && res[i]=='0') i++;
        return i<res.size()?res.substr(i):"0";
    }
};