class Solution {
public:
    bool winnerOfGame(string colors) {
        int acount=0;
        int bcount=0;
        int n=colors.size();
        for(int i=1;i<n-1;i++) {
            if(colors[i]==colors[i-1] && colors[i]==colors[i+1]) {
                if(colors[i]=='A') acount++;
                else bcount++;
            }
        }
        if(acount==bcount) false;
        
        return acount>bcount;
    }
};