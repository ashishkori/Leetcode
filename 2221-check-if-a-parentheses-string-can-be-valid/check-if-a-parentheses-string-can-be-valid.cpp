class Solution {
public:
    bool canBeValid2(string s, string locked) { 
        if(s.size()&1) return false;
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++) {
            if(s[i]=='('||locked[i]=='0') count++;
            else count--;
            if(count<0) return false; 
        }
        count=0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]==')'||locked[i]=='0') count++;
            else count--;
            if(count<0) return false;       
        }
        return true;
    }
    bool canBeValid1(string s, string locked) {
        stack<int> open, openClosed;
        if(s.size()&1) return false;
        for(int i=0;i<s.size();i++) {
            if(locked[i]=='1') {
                if(s[i]=='(') {
                    open.push(i);
                }else {
                    if(!open.empty()) open.pop();
                    else if(!openClosed.empty()) openClosed.pop();   
                    else return false;
                }
            } else {
                openClosed.push(i);
            }
        }
        while(!open.empty() && !openClosed.empty() && openClosed.top()>open.top()) {
                openClosed.pop();
                open.pop();
        }
        return open.empty()?true:false;
    }

     bool canBeValid(string s, string locked) { 
        return 0?canBeValid1(s,locked):canBeValid2(s,locked);
     }
};