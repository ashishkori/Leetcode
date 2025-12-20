class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int> res(deck.size());
        queue<int> qu;
        for(int i=0;i<deck.size();i++) {
            qu.push(i);
        }
        int i=0;
        while(!qu.empty()) {
            int top=qu.front();
            qu.pop();
            res[top]=deck[i++];
            top=qu.front();
            qu.pop();
            qu.push(top);
        }
        return res;

    }
};