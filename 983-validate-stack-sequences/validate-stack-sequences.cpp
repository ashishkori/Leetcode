class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        int i=0;
        int n=pushed.size();
        while(i<n && j<n) {
            if(i<n && (st.empty()||st.top()!=popped[j])) {
                st.push(pushed[i]);
                i++;
            }
            while(j<n && !st.empty() && st.top()==popped[j]) {
                j++;
                st.pop();
            } 
        }

       
        return st.empty();
    }
};