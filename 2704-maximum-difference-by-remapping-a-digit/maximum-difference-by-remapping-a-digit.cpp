class Solution {
public:
    int minMaxDifference(int num) {
        string  s=to_string(num);
        int idx=s.find_first_not_of('9');
        if(idx!=string::npos){
            char ch=s[idx];
            replace(s.begin(),s.end(),ch,'9');
        }

        string  s2=to_string(num);
        char c=s2[0];
        replace(s2.begin(),s2.end(),c,'0');
        //cout<< s<<" "<<s2;
        return (stoi(s)-stoi(s2));
    }
};