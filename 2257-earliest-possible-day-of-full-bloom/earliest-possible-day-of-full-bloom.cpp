class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>> plant(n);
        for(int i=0;i<plantTime.size();i++) {
            plant[i]={plantTime[i],growTime[i]};
        }
        auto lambda = [](pair<int,int>&p1, pair<int,int>&p2) {
            if(p1.second==p2.second) return p1.first>p2.first;

            return p1.second>p2.second;
        };
        sort(plant.begin(),plant.end(),lambda);
        int prevEnd=0;
        int maxDay=INT_MIN;
        for(int i=0;i<n;i++) {
            int p=plant[i].first;
            int g=plant[i].second;
            int totalTime=(prevEnd+p+g);
            maxDay=max(maxDay,totalTime);
            prevEnd+=p;
        }
        return maxDay;
    }
};