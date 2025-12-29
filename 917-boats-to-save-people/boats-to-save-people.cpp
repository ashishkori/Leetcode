class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0;
        int j=people.size()-1;
        sort(people.begin(),people.end()); 
        int count=0;
        while(i<=j) {
            if(people[i]+people[j]<=limit) {
                count++;
                i++;
                j--;
            } else if(people[j]<=limit) {
                count++;
                j--;
            } 
            else {
                count++;
                i++;
            }
        }
       // count+=(j-i+1);
        return count;
    }
};