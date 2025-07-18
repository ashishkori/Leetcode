class Solution {
private:
    int f1(int day,int canBuy,int limit,vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(limit==0||day==prices.size()){
            return 0;
        }
       
        if(dp[day][canBuy][limit]!=-1){
            return dp[day][canBuy][limit];
        }
        if(canBuy){
            return dp[day][canBuy][limit]=max(-prices[day]+f1(day+1,0,limit,prices,dp),f1(day+1,1,limit,prices,dp));
        }
        return dp[day][canBuy][limit]=max(prices[day]+f1(day+1,1,limit-1,prices,dp),f1(day+1,0,limit,prices,dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(3,-1)));
        return f1(0, 1, 2, prices,
                  dp); // since we haven't bought anything before the beginning
                       // of very first day, so we can buy stock on 1st day, so
                       // canBuy is 1 (acting as boolean)
    }
};