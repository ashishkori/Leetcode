class Solution {
public:
    char nextGreatestLetter1(vector<char>& letters, char target) {
        int l=0;
        int r=letters.size()-1;
        int res=-1;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(letters[mid]>target) {
                res=mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return (res!=-1)?letters[res]:letters[0];
    }
    char nextGreatestLetter2(vector<char>& letters, char target) { 
        int n=letters.size();
        int idx=upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        
        return (idx==n)?*letters.begin():letters[idx];
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        return 0?nextGreatestLetter1(letters, target):nextGreatestLetter2(letters, target);
    }
};