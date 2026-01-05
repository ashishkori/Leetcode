class Solution {
public:
int minSwaps3(string s) {
        int size=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='[') size++;
            else if (size>0) size--;
        }
        
        return (size+1)/2;
    }

    int minSwaps2(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='[') st.push(s[i]);
            else if (!st.empty()) st.pop();
            else st.push(s[i]);
        }
        
        return (st.size()+1)/2;
    }
    int minSwaps1(string s) {
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
    int minSwaps(string s) { 
        return 0?minSwaps1(s):(0?minSwaps2(s):minSwaps3(s));
    }
};