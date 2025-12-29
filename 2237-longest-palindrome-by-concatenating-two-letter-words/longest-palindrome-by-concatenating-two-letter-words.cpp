class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        for(auto x:words) {
            mp[x]++;
        }
        //string s="";
        int length=0;
        bool centerUsed=false;
        for(auto x:words) {
            string rev=x;
            reverse(rev.begin(),rev.end());
            if(rev!=x) {
                if(mp[x]>0 && mp[rev]>0) {
                    mp[x]--;
                    mp[rev]--;
                    length+=4;
                }
                
            } else if(rev==x && mp[x]>=2) {
                if(mp[x]>=2) {
                    mp[x]-=2;
                    length+=4;
                }
                
            } else if(!centerUsed && rev==x && mp[x]!=0) {
                 mp[x]--;
                 length+=2;
                 centerUsed=true;
            }
        }
        return length;
    }
};