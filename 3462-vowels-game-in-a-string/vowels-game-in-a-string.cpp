class Solution {
public:
    bool doesAliceWin(string s) {
    auto lambda = [](char x) {
        return (x=='a' || x=='e'||x=='i' || x=='o' || x=='u');
    };
  
    return any_of(s.begin(),s.end(),lambda);
    }
};