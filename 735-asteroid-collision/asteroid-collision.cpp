class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int i=0;i<asteroids.size();i++) {
            int x=asteroids[i];
            if(res.empty()||x>0) res.push_back(x);
            else {
                while(!res.empty() && res.back()>0 && x+res.back()<0) res.pop_back();
                if(res.size() && res.back()+x==0) res.pop_back();
                else if(res.empty() || res.back()+x<0 )res.push_back(x);
            }
        }
        return res;
    }
};