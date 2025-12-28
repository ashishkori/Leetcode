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
    // ListNode * reverse(ListNode* head) {
    //     if(!head) return head;

    //     ListNode* curr=head;
    //     ListNode* prev=nullptr;
    //     ListNode* next=nullptr;
    //     while(curr) {
    //         next=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=next;
    //     }

    //     return prev;
    // }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next = head;
        ListNode* prev=dummy;
        for(int i=1;i<left;i++) {
            prev=prev->next;
        }
         ListNode* curr=prev->next;
         for(int i=1;i<=right-left;i++) {
                 ListNode* tmp=prev->next;
                 prev->next=curr->next;
                 curr->next=curr->next->next;
                 prev->next->next=tmp;
         }
        return dummy->next;

    }
};