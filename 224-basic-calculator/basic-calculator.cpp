class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        unsigned int num=0;
        int res=0;
        int sign=1;
        for(int i=0;i<s.size();i++) {
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            } else if(s[i]=='(') {
                st.push(res);
                st.push(sign);
                num=0;
                res=0;
                sign=1;
            } else if(s[i]==')') {
                res+=sign*num;
                num=0;
                res=res*st.top(); st.pop();
                res+=st.top();st.pop();
            } else if(s[i]=='+') {
                cout<<" + "<<num<<endl;
                res+=sign*num;
                num=0;
                sign=1;

            } else if(s[i]=='-') {
                res+=sign*num;
                sign=-1;
                num=0;
            }
        }
        res+=sign*num;
        return res;
    }
};