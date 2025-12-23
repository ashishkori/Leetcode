class Solution {
public:
    void set(int &num, int c) {
        num|=(1<<c);
       
    }
    void unset(int &num, int c) {
        unsigned int i=0;
        num&=(~(1<<c));
    }
    int minimizeXor(int num1, int num2) {
        int res=num1;
        int n2_bit=__builtin_popcount(num2);
        int n1_bit=__builtin_popcount(num1);
        if(n2_bit==n1_bit) return num1;
        int bit=0;
        if(n2_bit>n1_bit) {
           while(n2_bit!=n1_bit) {
            if(((res>>bit)&1)==0) {
                set(res,bit);
                n1_bit++;
            }
            bit++;
           }
        } else {
            while(n2_bit!=n1_bit) {
            if(((res>>bit)&1)==1) {
                unset(res,bit);
                n1_bit--;
            }
            bit++;
           }
        }
        return res;
    }
};