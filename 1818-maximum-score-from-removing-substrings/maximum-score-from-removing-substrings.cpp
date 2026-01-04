class Solution {
public:
    string deleteS2(string s, string& sub){
        string res="";
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(!res.empty() && res.back()==sub[0] && s[i]==sub[1]){
                res.pop_back();
            } else res.push_back(s[i]);
        }
        return res;
    }
     string deleteS1(string s, string& sub){
        int i=0;
        for(int j=0;j<s.size();j++) {
            s[i]=s[j];
            i++;
            if(i>=2 && s[i-2]==sub[0] && s[i-1]==sub[1]) {
                i-=2;
            }
            
        }
        s.erase(s.begin()+i,s.end());
        return s;
    }
    string deleteS(string s, string& sub){
        return 1?deleteS1(s, sub):deleteS2(s, sub);
    }
    int maximumGain(string s, int x, int y) {
        string maxStr=(x>y)?"ab":"ba";
        string minStr=(maxStr=="ba")?"ab":"ba";

        string tmp1=deleteS(s,maxStr);

        string tmp2=deleteS(tmp1, minStr);
        int res=(((s.size()-tmp1.size())/2)*max(x,y))+(((tmp1.size()-tmp2.size())/2)*min(x,y));
        return res;
    }
};