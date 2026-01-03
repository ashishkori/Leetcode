class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
    // Use a max heap (priority queue in C++ defaults to max-heap)
    priority_queue<int> maxHeap(nums.begin(), nums.end());
    long long score = 0;

    // Perform k operations
    for (int i = 0; i < k; ++i) {
        // Get the largest element from the heap
        int topElement = maxHeap.top();
        maxHeap.pop();
        
        // Add it to the score
        score += topElement;
        
        // Calculate the new value and push it back to the heap
        int newElement = ((topElement+2)/3);
        maxHeap.push(newElement);
    }

    return score;
}

};