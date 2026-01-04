class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        int i=0;
        int n=pushed.size();
        while(i<n && j<n) {
            st.push(pushed[i]);
            while(j<n && !st.empty() && st.top()==popped[j]) {
                j++;
                st.pop();
            } 
            i++;
        }

       
        return st.empty();
    }
};