class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        //time complexity: O(n)
        //space complexity: O(1)

        int i;
        int b=0,a=0,l=0,o=0,n=0;

        //loop to traverse over string 'text' increase the count of letters: b,a,l,o,n
        for(i=0;i<text.size();i++)
        {
            if(text[i]=='b')
                b++; 
            else if(text[i]=='a')
                a++;
            else if(text[i]=='l')
                l++;
            else if(text[i]=='o')
                o++;
            else if(text[i]=='n')
                n++;
        }

        //setting 'ans' to minimum occurence of these characters(it will be the minimum count of "balloon'")
        int ans=min({b,a,l/2,o/2,n});
        return ans;
    }
};