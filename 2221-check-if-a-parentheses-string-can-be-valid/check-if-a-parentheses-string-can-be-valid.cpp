class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> open, openClosed;
        if(s.size()&1) return false;
        for(int i=0;i<s.size();i++) {
            if(locked[i]=='1') {
                if(s[i]=='(') {
                    open.push(i);
                }else {
                    if(open.empty() && openClosed.empty()) return false;
                    else if(!open.empty()) open.pop();
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
        cout<<"Size: "<<open.size()<<" empty "<<open.empty()<<endl;
        return open.empty()?true:false;
    }
};