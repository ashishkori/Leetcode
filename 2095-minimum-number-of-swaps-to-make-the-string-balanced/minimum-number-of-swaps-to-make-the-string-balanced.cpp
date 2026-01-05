class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(!st.empty() && st.top()=='[' && s[i]==']') st.pop();
            else st.push(s[i]);
        }
        int count=0;
        while(!st.empty()) {
            if(st.top()==']') count++;
            st.pop();
        }
        return (count+1)/2;
    }
};