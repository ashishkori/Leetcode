class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefix(arr.size()+1);
        prefix[0]=0;

        for(int i=0;i<arr.size();i++) {
            prefix[i+1]=prefix[i]^arr[i];
        }
        int count=0;
        for(int i=0;i<prefix.size();i++) {
            for(int k=i+1;k<prefix.size();k++) {
                if(prefix[i]==prefix[k]) {
                    count+=(k-i-1);
                }
            }
        }
        return count;
    }
};