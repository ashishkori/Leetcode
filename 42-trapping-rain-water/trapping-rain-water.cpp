class Solution {
public:
    int trap(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        int lmax=0,rmax=0, total=0;
        while(left<right) {
            if(arr[left]<arr[right]) {
                if(arr[left]<lmax) total+=lmax-arr[left];
                else lmax=arr[left];
                left++;

            } else {
                if(arr[right]<rmax) total+=rmax-arr[right];
                else rmax=arr[right];
                right--;
            }
        }
        return total;

    }
};