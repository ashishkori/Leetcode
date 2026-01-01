class Solution {
public:
    typedef pair<int,int> P;
    struct lambda {
        bool operator()(P& p1, P& p2) {
            return p1.second<p2.second;
        };
    };
    string frequencySort2(string s) {
        unordered_map<char,int> mp;
        priority_queue<P, vector<P>,lambda> pq;
        for(int i=0;i<s.size();i++) {
            mp[s[i]]++;
        }
  
        for(auto [x,c]:mp) {
            pq.push({x,c});
        }
        string res="";
        while(!pq.empty()) {
            char x=pq.top().first;
            int count=pq.top().second;
            pq.pop();
            while(count>0) {
                res+=x;
                count--;
            }
        }
        return res;
    }
    static bool compare(pair<char,int> &p1, pair<char,int>&p2) {
        return  (p1.second > p2.second) ;
    }
    string frequencySort1(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++) {
            mp[s[i]]++;
        }
        vector<pair<char,int>> vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),compare);
        string res="";
        for(auto x:vec) {
            for(int i=0;i<x.second;i++) {
                res+=x.first;
            }
        }
        return res;
    }
    string frequencySort(string s)  {
        return 0?frequencySort1(s):frequencySort2(s);
    }
};