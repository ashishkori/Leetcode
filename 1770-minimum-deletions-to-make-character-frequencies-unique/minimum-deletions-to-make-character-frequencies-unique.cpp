class Solution {
public:
    int minDeletions(string s) {
        vector<int> vec(26,0);
        for(char ch:s) {
            vec[ch-'a']++;
        }
        sort(vec.begin(),vec.end(),greater<int>());
        int res=0;
        for(int i=1;i<26 && vec[i]>0;i++){
            if(vec[i]>=vec[i-1]){
                int prev=vec[i-1];
                int org=vec[i];
                vec[i]=max(0,prev-1);
                res+=org-vec[i];
            }
        }
        return res;
    }
};