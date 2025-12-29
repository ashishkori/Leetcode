class Solution {
public:
    int maximum69NumberS (int num) {
        string s=to_string(num);
        for(int i=0;i<s.size();i++) {
            if(s[i]=='6') {
                s[i]='9';
                break;
            }
        }
        return stoi(s);
    }
    int maximum69NumberN (int num) { 
        int n=num;
        int pl=0;
        int pls=-1;

        while(n) {
            if(n%10==6) {
                pls=pl;
            }
            n/=10;
            pl++;
        }
        if(pls==-1) return num;

        num=num+(3*pow(10,pls));
        return num;

    }
    int maximum69Number (int num) {
        return 0?maximum69NumberS(num):maximum69NumberN(num);
    }
};