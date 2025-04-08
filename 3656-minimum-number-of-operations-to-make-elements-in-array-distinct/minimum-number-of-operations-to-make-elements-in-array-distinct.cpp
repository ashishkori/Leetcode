class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> arr(100+1,0);
        //int lastdup=0;
        for(int i=nums.size()-1; i>=0;i--) {
            if(arr[nums[i]]!=0) {
                return (i+3)/3;
            }
            arr[nums[i]]++;
        }
        
        return 0;
    }
};