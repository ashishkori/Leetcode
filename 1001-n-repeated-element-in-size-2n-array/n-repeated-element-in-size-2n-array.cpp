class Solution {
public:
    int repeatedNTimes1(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &x:nums) {
            if(st.find(x)!=st.end()) return x;
            st.insert(x);
        }
        return -1;
    }
    int repeatedNTimes2(vector<int>& A) {
        for (int i = 0; i < A.size() - 1; ++i)
            if (A[i] == A[i + 1] || (i + 2 < A.size() && A[i] == A[i + 2]))
                return A[i];
        
        return A[0];
    }

    int repeatedNTimes(vector<int>& A) { 
        return 0?repeatedNTimes1(A):repeatedNTimes2(A);
    }
};


