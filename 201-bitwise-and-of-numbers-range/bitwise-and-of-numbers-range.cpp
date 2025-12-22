class Solution {
public:
    int i=0;
    int rangeBitwiseAnd(int left, int right) {
        while(left !=right) {
            i++;
            left>>=1;
            right>>=1;
        }
        return left<<i;
    }
};