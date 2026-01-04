class Solution {
public:
    string removeKdigits2(string num, int k) {
        string res="";
        for(char c:num) {
            while(k>0 && !res.empty() && res.back()>c){
                k--;
                res.pop_back();
            }
            if(res.empty() && c=='0') continue;
            res.push_back(c); 
        }

        while(k>0 && !res.empty()) {
            res.pop_back();
            k--;
        }
        return res.size()?res:"0";

    }
    string removeKdigits1(string num, int k) {
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
     string removeKdigits(string num, int k) {
        return 0?removeKdigits1(num,k):removeKdigits2(num,k);
     }
};