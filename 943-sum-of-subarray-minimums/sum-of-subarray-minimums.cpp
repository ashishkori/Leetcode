class Solution {
public:
    //#define MOD 1e9+7
    void createLHS(vector<int>& arr, vector<int>& LHS) {
        stack<int> st;
        int n=arr.size();

        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[st.top()]>=arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                LHS[i]=-1;
            } else {
                LHS[i]=st.top();
            }
            st.push(i);
        }
    }

    void createRHS(vector<int>& arr, vector<int>& RHS) {
        stack<int> st;
        int n=arr.size();

        for(int i=arr.size()-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()]>arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                RHS[i]=arr.size();
            } else {
                RHS[i]=st.top();
            }
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> LHS(n,-1);
        vector<int> RHS(n,n);
        createLHS(arr, LHS);
        createRHS(arr, RHS);
        long long sum=0;
        int M= 1e9+7;
        for(int i=0;i<arr.size();i++) {
            long long ls=i-LHS[i];
            long long rs=RHS[i]-i;
            long long ways=ls*rs;

            long long totalSum=arr[i]*ways;
            sum=(sum+totalSum)%M;
        }
        return sum;
    }
};