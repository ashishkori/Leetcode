class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int sum=accumulate(apple.begin(),apple.end(),0);
        int res=-1;
        for(int i=0;i<capacity.size();i++) {
            sum-=capacity[i];
            if(sum<=0) {
                res=i+1;
                break;
            }
        }
        return res;
    }
};