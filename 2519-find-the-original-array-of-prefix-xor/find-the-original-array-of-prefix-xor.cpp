class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
    //  int curr=pref[0];

    //   for(int i=pref.size()-1;i>=0;i--) {
    //     curr=pref[i];
    //     pref[i]=pref[i]^pref[i-1];
    //     curr=pref[i];
    //   }
    vector<int> res(pref.size(),0);
    res[0]=pref[0];
    for(int i=1;i<pref.size();i++) {
        res[i]=pref[i]^pref[i-1];
    }
    return res;
    }
};