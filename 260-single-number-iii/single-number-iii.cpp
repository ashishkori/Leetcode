class Solution {
public:
    vector<int> singleNumber1(vector<int> &nums) {
	sort (nums.begin(), nums.end());
	vector<int> ans;
	int i = 0, n = nums.size();
	while (i < n - 1)
	    // skip equal elements
		if (nums[i] == nums[i + 1]) i += 2;
		// generate ans
		else {
			ans.push_back(nums[i++]);
			if (ans.size() == 2)
				return ans;
		}
	// corner case
	if (ans.size() == 1) 
		ans.push_back(nums.back());
	return ans;
    }
    int findrSetbiy(int n) {
        int i=0;
        while((n&1)==0) {
            i++;
            n>>=1;
        }
        return i;
    }
    vector<int> singleNumber2(vector<int> &nums) { 
        int xorn=0;
        for(auto x:nums) xorn^=x;
        int xor1=0,xor2=0;
        int idx=findrSetbiy(xorn);
        for(auto x:nums) {
            if(x&(1<<idx)) {
                xor1^=x;
            } else {
                 xor2^=x;
            }
        }
        return {xor1,xor2};

    }

    vector<int> singleNumber(vector<int> &nums) {
	return 1?singleNumber1(nums):singleNumber2(nums);
    }
};