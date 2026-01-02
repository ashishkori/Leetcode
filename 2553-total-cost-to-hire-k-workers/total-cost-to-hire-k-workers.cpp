class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        int i=0;
        int j=costs.size()-1;
        int count=0;
        long long tcost=0;
        while(count<k) {
            while(pq1.size()<candidates && i<=j) {
                pq1.push(costs[i++]);
            } 
            while(pq2.size()<candidates && i<=j) {
              pq2.push(costs[j--]);
            }

            int c1=!pq1.empty()?pq1.top():INT_MAX;
            int c2=!pq2.empty()?pq2.top():INT_MAX;   

            if(c1<=c2) {
                tcost+=c1;
                pq1.pop();
            } else {
                tcost+=c2;
                pq2.pop();
            }       
            count++;
        }
        return tcost;
    }
};