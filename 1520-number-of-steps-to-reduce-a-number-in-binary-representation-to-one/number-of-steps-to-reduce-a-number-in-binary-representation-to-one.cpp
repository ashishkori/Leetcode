class Solution {
public:
    void addOne(string &s) {
        int i=s.size()-1;
        while(i>=0 && s[i]=='1') {
            s[i]='0';
            i--;
        }
        if(i<0) {
            s='1'+s;
        } else {
            s[i]='1';
        }
    }
    int numSteps1(string s) {
        //int n=s.size();
        int count=0;
        while(s.size()!=1) {
            int n=s.size();
            if(s[n-1]=='0') {
                s.pop_back();
            } else {
                addOne(s);
            }
            count++;
        }
        return count;
    }

    int numSteps2(string s) {
        int i=s.size()-1;
        int carry=0;
        int count=0;
        while(i>0) {
            int value=s[i]-'0';
            if((value+carry)%2==1) {
                count+=2;
                carry=1;
            } else {
                count++;
            }
            i--;
        }
        return carry+count;
     }
     int numSteps(string s) {
        return 0?numSteps1(s):numSteps2(s);
     }
};