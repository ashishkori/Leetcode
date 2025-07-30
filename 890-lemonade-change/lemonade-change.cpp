class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> coin(3,0);
        bool result=true;
        for(int x:bills) {
            if(x==5) coin[0]++;
            else if(x==10) {
                if(coin[0]) {
                    coin[0]--;
                    coin[1]++;
                } else return false;
            } else {
                if(coin[0]>0&&coin[1]>0) {
                    coin[0]--;
                    coin[1]--;
                    coin[2]++;
                } else if(coin[0]>=3) {
                    coin[0]-=3;
                } else return false;
            }
        }
        return result;
    }
};