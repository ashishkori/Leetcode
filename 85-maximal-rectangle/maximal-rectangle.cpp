class Solution {
public:
    vector<int> getNSL(vector<int>& height){
        int n=height.size();
        stack<int> st;
        vector<int> res(n,-1);
        for(int i=0;i<n;i++) {
            while(!st.empty() && height[st.top()]>=height[i]) {
                st.pop();
            }
            if(st.empty()) res[i]=-1; 
            else res[i]=st.top();
            st.push(i);
        }
        return res;
    }

     vector<int> getNSR(vector<int>& height){
        int n=height.size();
        stack<int> st;
        vector<int> res(n,n);
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && height[st.top()]>=height[i]) {
                st.pop();
            }
            if(st.empty()) res[i]=n;
            else res[i]=st.top();
            st.push(i);
        }
        return res;
    }

    int findMaxArea(vector<int>& height) {
        int n=height.size();

        vector<int>NSL=getNSL(height);
        vector<int>NSR=getNSR(height);
        int area=0, maxArea=0;
        vector<int> width(n);
        for(int i=0;i<n;i++) {
            width[i]=NSR[i]-NSL[i]-1;
        }
        for(int i=0;i<n;i++) {
            area= width[i]*height[i];
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> height(n,0);
        for(int i=0;i<n;i++) {
            if(matrix[0][i]=='1') height[i]=1;
            else  height[i]=0;
        }

        int maxArea=findMaxArea(height);

        for(int row=1; row<m;row++) {
            for(int col=0;col<n;col++) {
                if(matrix[row][col]=='0') height[col]=0;
                else height[col]+=1;
            }
            maxArea=max(maxArea,findMaxArea(height));
        }

        return maxArea;
    }
};