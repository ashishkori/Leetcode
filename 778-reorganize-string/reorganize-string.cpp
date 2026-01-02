class Solution {
public:
    typedef pair<int,char> P;
    struct lambda {
        bool operator()(P& p1, P& p2) { 
            return p1.first<p2.first;
        }
    };
    string reorganizeString(string s) {
       priority_queue<P,vector<P>,lambda> pq;
       string res="";
       map<char, int> mp;
       for(char ch:s){
        mp[ch]++;
       }
       int n=s.size();
       for(auto &it:mp) {
            if(it.second>(n+1)/2) return res;
            pq.push({it.second,it.first});
       }
       while(!pq.empty()) {
         auto tmp=pq.top();
         res+=tmp.second;
         pq.pop();
         if(pq.empty()) break;
         auto tmp2=pq.top();
         res+=tmp2.second;
         pq.pop();
         if(tmp.first>1) {
            pq.push({tmp.first-1,tmp.second});
         }
        if(tmp2.first>1) {
            pq.push({tmp2.first-1,tmp2.second});
         }
       }
       return res;
    }
};