class Solution {
public:
    string largestOddNumber(string num) {
        int k = -1;
        for (int i = num.size() - 1; i >= 0; i--) {
            int Digit = num[i] - '0'; 
            if (Digit % 2 != 0) {
                k = i;
                break;
            }
        }
        return k == -1 ? "" : num.substr(0, k + 1);
    }
};