class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 0) return head;

        ListNode* curr = head;
        int n = 1;
        while(curr -> next != NULL){
            curr = curr -> next;
            n++;
        }
        k %= n;
        curr -> next = head;
        int steps = n - k;
        ListNode* newTail = curr;
        while(steps--){
            newTail = newTail -> next;
        }
        ListNode* newHead = newTail -> next;
        newTail -> next = NULL;

        return newHead;
    }
};
