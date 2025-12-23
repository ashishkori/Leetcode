class Solution {
public:
    void set(int &num, int c) {
        num|=(1<<c);
       
    }
    void unset(int &num, int c) {
        num&=(~(1<<c));
    }
    bool isSet(int num, int c) {
        return ((num>>c)&1 !=0);
       
    }

    bool isUnset(int num, int c) {
        return ((num>>c)&1==0);
    }
    int minimizeXor1(int num1, int num2) {
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

    int minimizeXor2(int num1, int num2) {
        int res=0;
        int cbit=__builtin_popcount(num2);

        for(int i=31;i>=0 && cbit>0;i--) {
            if(isSet(num1,i)){
                set(res,i);
                cbit--;
            }
        }
        //cout<<"CBIT "<<cbit<<" RES "<<res;
        for(int i=0;i<32 && cbit>0 ;i++) {
            if(!isSet(num1,i)){
              //  cout<<"CBIT "<<cbit<<" RES "<<res;
                set(res,i);
                cbit--;
            }
        }
        return res;
    }
    int minimizeXor(int num1, int num2) {
        return 0?minimizeXor1(num1, num2):minimizeXor2(num1, num2);
     }
};