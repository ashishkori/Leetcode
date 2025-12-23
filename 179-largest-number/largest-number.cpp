class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // vector<string> s;
        // for(auto x:nums) s.push_back(to_string(x));
        auto lambda=[](int& n1, int& n2) {
            string s1=to_string(n1);
            string s2=to_string(n2);
            return (s1+s2)>(s2+s1);
        };
        sort(nums.begin(),nums.end(),lambda);
        string res="";
        if(nums[0]==0) return "0";
        for(auto x:nums) res+=to_string(x);

        return res;
    }
};