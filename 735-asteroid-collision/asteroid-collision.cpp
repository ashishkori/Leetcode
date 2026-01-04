class Solution {
public:
 vector<int> asteroidCollision2(vector<int>& asteroids) {
        vector<int> res;
        for(auto &a:asteroids) {
            if(res.empty() || a>0) { 
                res.push_back(a);
                continue;
            }
            int sum=res.back()+a;
            while(!res.empty() && sum<0) {
                sum=res.back()+a;
                res.pop_back();
            }
            if(sum==0 && !res.empty())  res.pop_back();
            else res.push_back(a);
        }
        return res;
    }
    vector<int> asteroidCollision1(vector<int>& asteroids) {
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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        return 0?asteroidCollision1(asteroids):asteroidCollision1(asteroids);
    }
};