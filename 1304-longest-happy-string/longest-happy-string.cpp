class Solution {
public:
    typedef pair<int,char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P,vector<P>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string res="";
        while(!pq.empty()) {
            auto f=pq.top(); pq.pop();
            if(res.size()>=2 && res[res.size()-1]== f.second && res[res.size()-2]== f.second){
            if(pq.empty()) break;
            auto s=pq.top(); pq.pop();
            res+=s.second;
            s.first--;
            if(s.first>0) pq.push(s);
        } else {
            res+=f.second;
            f.first--;
        }
        if(f.first>0) pq.push(f);
        }
      return res;
    }
  
};