class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        if(arr.size()<3) return false;
        for(int i=0;i<3;i++) {
            if(arr[i]%2) count++; 
        }
        if(count==3) return true;
        for(int i=3; i<arr.size();i++) {
            if(arr[i-3]%2==1) count--;
            if(arr[i]%2)count++;
            if(count ==3) return true; 
        }
        return false;
    }
};