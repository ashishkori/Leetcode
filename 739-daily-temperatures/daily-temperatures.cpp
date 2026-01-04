class Solution {
public:
    vector<int> dailyTemperatures2(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]) {
                st.pop();
            }
            if(st.empty()) {
                res[i]=0;
            } else {
                res[i]=st.top()-i;
            }
            st.push(i);
        }
        return res;
    }
    vector<int> dailyTemperatures1(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n=temperatures.size();
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first<=temperatures[i]) {
                st.pop();
            }
            if(st.empty()) {
                res[i]=0;
            } else {
                res[i]=st.top().second-i;
            }
            st.push({temperatures[i],i});
        }
        return res;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return 0?dailyTemperatures1(temperatures):dailyTemperatures2(temperatures);
    }
};