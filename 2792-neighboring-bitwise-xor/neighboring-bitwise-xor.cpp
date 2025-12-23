class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int>res(n,0);
        res[0]=0;
        for(int i=0;i<derived.size()-1;i++) {
            res[i+1]=res[i]^derived[i];
        }
        if(derived[n-1]==(res[0]^res[n-1])) return true;
        
        res[0]=1;
        for(int i=0;i<derived.size()-1;i++) {
            res[i+1]=res[i]^derived[i];
        }
        if(derived[n-1]==(res[0]^res[n-1])) return true;
        
        return false;
    }
};