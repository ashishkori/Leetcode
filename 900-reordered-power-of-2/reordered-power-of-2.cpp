class Solution {
public:
int getCountFormat(int n) {
        int vec=0;

        //256
        //256/10 = 25
        while(n) {
            vec+=pow(10,n%10);
            n /= 10;
        }

        return vec;
    }

    bool reorderedPowerOf2_3(int n) {
        int input = getCountFormat(n);

        for(int p = 0; p <= 29; p++) {
            if(input == getCountFormat(1 << p)) {
                return true;
            }
        }

        return false;
    }

     vector<int> getVectorCountFormat(int n) {
        vector<int> vec(10, 0);

        //256
        //256/10 = 25
        while(n) {
            vec[n%10]++;
            n /= 10;
        }

        return vec;
    }

    bool reorderedPowerOf2_2(int n) {
        vector<int> input = getVectorCountFormat(n);

        for(int p = 0; p <= 29; p++) {
            if(input == getVectorCountFormat(1 << p)) {
                return true;
            }
        }

        return false;
    }

    string getSortedStr(int n) {
        string s = to_string(n);
        sort(begin(s), end(s));
        return s;
    }

    bool reorderedPowerOf2_1(int n) {
        string s = getSortedStr(n);

        //check all 2 powers and see if it matches with s
        //2^29
        for(int p = 0; p <= 29; p++) {
            if(s == getSortedStr(1 << p)) {
                return true;
            }
        }

        return false;
    }

    bool reorderedPowerOf2(int n) {
       return  0?reorderedPowerOf2_1(n):(0?reorderedPowerOf2_2(n):reorderedPowerOf2_3(n));
    }
};