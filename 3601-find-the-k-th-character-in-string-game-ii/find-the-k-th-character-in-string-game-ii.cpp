class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1) return 'a';
        long long len=1;
        int i=0;
        int op=0;
        for(int i=0;i<operations.size();i++) {
            len*=2;
            if(len>=k) {
                op=operations[i];
                break;
            }
        }
        long long newK=k-len/2;
        char ch=kthCharacter(newK, operations);
        if(op==1) {
            if(ch=='z') ch='a';
            else ch+=1;
        }
        return ch;
    }
};