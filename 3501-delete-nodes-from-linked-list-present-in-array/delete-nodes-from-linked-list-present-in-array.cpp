/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
     unordered_set<int> toDelete(nums.begin(), nums.end());
    
    // Step 2: Use a dummy node to handle edge cases like head deletion.
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* prev = dummy;
    ListNode* curr = head;
    
    // Step 3: Traverse the linked list and delete nodes with values in toDelete.
    while (curr != nullptr) {
        if (toDelete.count(curr->val)) {
            // Skip the node by adjusting the prev->next pointer.
            prev->next = curr->next;
        } else {
            // Move prev forward only if the current node is not deleted.
            prev = curr;
        }
        // Move to the next node.
        curr = curr->next;
    }
    
    // Step 4: Return the modified list starting from dummy->next (new head).
    return dummy->next;
}
};