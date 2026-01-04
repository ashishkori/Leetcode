class Solution {
public:
     vector<int> getNSL(vector<int>& heights) {
        int n=heights.size();
        vector<int> res(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();

            if(!st.empty()) res[i]=st.top();
            st.push(i); 
        }
        return res;
     }
    vector<int> getNSR(vector<int>& heights) {
        int n=heights.size();
        vector<int> res(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();

            if(!st.empty()) res[i]=st.top();
            st.push(i); 
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSL=getNSL(heights);
        vector<int> NSR=getNSR(heights);
        int n=heights.size();
        int maxArea=0;
        for(int i=0;i<n;i++) {
            int width=NSR[i]-NSL[i]-1;
            int area=width*heights[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};