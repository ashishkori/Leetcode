class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>> vec;
        for(int i=0;i<positions.size();i++) {
            vec.push_back({positions[i],i});
        }
        sort(vec.begin(),vec.end());
        stack<int>st;
        for(int i=0;i<vec.size();i++) {   
            int idx=vec[i].second;  
            if(directions[idx]=='R') st.push(idx);
            else {
                while(!st.empty() && directions[st.top()] =='R' && healths[idx]>0){
                    if(healths[st.top()]==healths[idx]){
                        healths[st.top()]=0;
                        healths[idx]=0;
                    } else if(healths[st.top()]>healths[idx]) {
                        healths[st.top()]--;
                        healths[idx]=0;
                    } else {
                        healths[st.top()]=0;
                        healths[idx]--;                     
                    }
                    if(healths[st.top()]==0) st.pop();
                }
                if(healths[idx]>0) st.push(idx);
            }    
        }
        vector<int> res;
        for(auto x:healths) {
            if(x>0) res.push_back(x);
        }
        return res;
    }
};