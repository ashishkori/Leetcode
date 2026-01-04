class Solution {
public:
    int evalRPN2(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string,function<int (int,int)> > mp={
            {"+",[](int a, int b) { return a+b;}},
            {"-",[](int a, int b) { return a-b;}},
            {"*",[](int a, int b) { return a*b;}},
            {"/",[](int a, int b) { return a/b;}},
        };
        for(string &x:tokens) {
            if(x=="+" || x=="-" || x=="*" || x=="/") {
                int b=st.top(); st.pop();
                int a=st.top(); st.pop();
                int res=mp[x](a,b);
                st.push(res);
            } else {
                st.push(stoi(x));
            }
        }
        return st.top();
    }

    int oprate(int a, int b, string c) {
            int res=-1;
            if(c=="+") {
                res=a+b;
            } else  if(c=="-") {
                res=a-b;
            } else  if(c=="*") {
                res=a*b;
            } else  if(c=="/") {
                res=a/b;
            } 
            return res;
        }
    int evalRPN1(vector<string>& tokens) {
        stack<int> st;
        for(string &x:tokens) {
            if(x=="+" || x=="-" || x=="*" || x=="/") {
                int b=st.top(); st.pop();
                int a=st.top(); st.pop();
                int res=oprate(a, b, x);
                st.push(res);
            } else {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
    int evalRPN(vector<string>& tokens) { 
        return 0?evalRPN1(tokens):evalRPN2(tokens);
    }
};