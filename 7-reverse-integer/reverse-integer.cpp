class Solution {
public:
    int reverse(int x) {
    int neg=1;
    if(x<0) neg = -1;
    string s=to_string(x);
    std::reverse(s.begin(),s.end());
    long res = neg*stol(s);
    if(res>INT_MAX || res<INT_MIN) return 0;
    return (int) res;
    }

};