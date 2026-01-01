class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || left.top()>num) {
            left.push(num);
        } else {
            right.push(num);
        } 
        
        if(left.size()>1+right.size()) {
            right.push(left.top());
            left.pop();
        } else if(right.size()>left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        //int len=+right.size();
        double res=0;
        if(left.size() != right.size()) {
            res= left.top();
        } else {
            res = ((double)left.top()+(double)right.top());
            res/=2;
        }
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */