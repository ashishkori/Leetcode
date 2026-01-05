class Solution {
public:
     int minimumDeletions2(string s) { 
        int count_a=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='a') count_a++;
        }
        int count_b=0;
        int res=s.size();
        for(int i=0;i<s.size();i++) {
            if(s[i]=='a') count_a--;
        
            res=min(res, (count_a+count_b));
            if(s[i]=='b') count_b++;
        }
        return res;
     }
    int minimumDeletions1(string s) {
        stack<char> st;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]=='a' && st.top()=='b') {
                st.pop();
                count++;
            } else {
                st.push(s[i]);
            }
        }
        return count;
    }
    int minimumDeletions(string s) { 
        return 0?minimumDeletions1(s):minimumDeletions2(s);
    }
};