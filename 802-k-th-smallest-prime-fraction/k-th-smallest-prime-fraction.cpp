class Solution {
public:
    typedef vector<double> V;
    vector<int> kthSmallestPrimeFraction2(vector<int>& arr, int k) {
        priority_queue<V,vector<V>,greater<V>> pq;
        int n=arr.size();
        for(int i=0;i<arr.size()-1;i++) {
            vector<double> tmp={1.0*arr[i]/arr[n-1],1.0*i,(double)(n-1)};
            pq.push(tmp);
        }
        int smallest=1;
        vector<int>res;
        while(smallest<k) {
            auto tmp=pq.top();
            pq.pop();
            int i=tmp[1];
            int j=tmp[2]-1;
            vector<double> tmp1={1.0*arr[i]/arr[j],1.0*i,1.0*j};
            pq.push(tmp1);
            smallest++;
        }
        res.push_back(arr[(int)pq.top()[1]]);
        res.push_back(arr[(int)pq.top()[2]]);

        return res;
    }

    vector<int> kthSmallestPrimeFraction1(vector<int>& arr, int k) {
       // sort(arr.begin(),arr.end());
        priority_queue<vector<double>> pq;
        for(int i=0;i<arr.size();i++) {
            for(int j=i+1;j<arr.size();j++) {
                double x=(double)arr[i]/arr[j];
                vector<double> tmp={x,(double)arr[i],(double)arr[j]};
                pq.push(tmp);
                if(pq.size()>k) pq.pop();
            }
        }
        vector<int>res;
        // int i=pq.top()[1];
        // int j=pq.top()[2];
        res.push_back((int)pq.top()[1]);
        res.push_back((int)pq.top()[2]);

        return res;
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) { 
        return 0?kthSmallestPrimeFraction1(arr,k):kthSmallestPrimeFraction2(arr,k);
    }
};