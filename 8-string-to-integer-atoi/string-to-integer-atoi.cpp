class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, n = s.length();
        long result = 0;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Check optional sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // 4. Clamp to 32-bit integer range
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;

            i++;
        }

        return result * sign;
    }
};