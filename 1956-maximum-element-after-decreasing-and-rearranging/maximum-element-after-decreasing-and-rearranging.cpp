class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int res=-1;
        for(int i=0;i<arr.size();i++) {
            if(i==0){ 
                arr[i]=1;
            } else if(abs(arr[i]-arr[i-1])>1) {
                arr[i]=arr[i-1]+1; 
            }
            res = max(res,arr[i]);
        }
        return res;
    }
};