class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count=0;
        string res="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            bool ignore=false;
            if(c=='(') {
                count++;
            } else if(c==')') {
                if(count<=0) {
                    ignore=true;
                    count=0;
                }
                else count--;
            }
            if(!ignore) res+=c;
        }
        //cout<<"RES " << res<<endl;
        s="";
        for(int i=res.size()-1;i>=0;i--) {
            if(res[i]=='(' && count >0){
                count--;
                continue;
            }
            s.push_back(res[i]);
        }
        reverse(s.begin(),s.end());
        return s;
    }
};