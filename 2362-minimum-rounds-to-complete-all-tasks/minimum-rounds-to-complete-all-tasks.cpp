class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
        for(auto x:tasks) mp[x]++;
        int count=0;
        for(auto itr=mp.begin();itr !=mp.end();itr++) {
            int c=itr->second;
            if(c<2) return -1;
            count+=c/3;
            if(c%3) count++;
        }
        return count;
    }
};