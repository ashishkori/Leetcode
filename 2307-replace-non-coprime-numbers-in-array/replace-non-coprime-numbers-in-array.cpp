#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            while (!result.empty()) {
                int a = result.back();
               // int b = result[result.size() - 2];
                int g = gcd(a, num);
                if (g > 1) {
                    result.pop_back();
                    long long lcm = (long long)a / g * num;
                    num=lcm;
                } else {
                    break;
                }
            }
            result.push_back(num);
        }
        return result;
    }
};