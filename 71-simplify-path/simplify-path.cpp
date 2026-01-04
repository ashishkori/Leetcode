class Solution {
public:
    string simplifyPath2(string path) {
        stringstream ss(path);
        vector<string> vec;
        string tok="";
        while(getline(ss,tok,'/')) {
            if(tok=="" || tok==".") continue;

            if(tok!=".."){
                vec.push_back(tok);
            } else {
                if(!vec.empty()) vec.pop_back();
            }
        }
        string res="";
        if(vec.empty()) return "/";
        
        for(auto x:vec) {
            res=res+"/"+x;
        }
        return res;
    }
     string simplifyPath1(string path) {
          stringstream ss(path);
        stack<string> st;
        string tok="";
        while(getline(ss,tok,'/')) {
            if(tok=="" || tok==".") continue;

            if(tok!=".."){
                st.push(tok);
            } else {
                if(!st.empty()) st.pop();
            }
        }
        string res="";
        if(st.empty()) return "/";
        
        while(!st.empty()){
            res="/"+st.top()+res;
            st.pop();
        }
        return res;
     }
     string simplifyPath(string path) { 
        return 0?simplifyPath1(path):simplifyPath2(path);
     }
};