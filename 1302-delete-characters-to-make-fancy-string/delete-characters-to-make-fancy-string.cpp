class Solution {
public:
    string makeFancyString(string s) {
        // Handle edge cases: empty string or single character
        if (s.length() <= 2) {
            return s;
        }
        // Result string to build our fancy string
        string result = s.substr(0,2);
        int j=result.size()-1;
        // Iterate through each character in the input string
        for (int i = 2; i < s.length(); i++) {
            // Get the current character
            char currentChar = s[i];
            if(result[j] == result[j-1] && result[j] == currentChar) {
                continue;
            }
            result += currentChar;
            j++;
        }
        return result;
    }
};