class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int ans = start ^ goal, ctr = 0;

        return __popcount(ans);
       /* for(int i = 0; i < 31; ++i)
        {
            if(ans & (1 << i)) ctr++;
        }
        return ctr;
    */


        
    }
};