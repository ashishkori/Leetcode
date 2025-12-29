class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalFuel=accumulate(gas.begin(),gas.end(),0);
        int totalCost=accumulate(cost.begin(),cost.end(),0);
        if(totalFuel<totalCost) return -1;
        int index=0;
        int netCost=0;
        for(int i=0;i<cost.size();i++) {
            netCost+=(gas[i]-cost[i]);
            if(netCost<0) {
                netCost=0;
                index=i+1;
            }
        }
        return index;
    }
};