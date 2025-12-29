class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev=0;
        int i=0;
        int n=colors.size();
        int cost=0;
        while(i<n) {
            
            if(i>0 && colors[i-1]!=colors[i]) {
                 prev=0;
            }

            int curr=neededTime[i];
            cost+=min(curr,prev);
            prev=max(curr,prev);
            i++;
        }
        return cost;
    }
};