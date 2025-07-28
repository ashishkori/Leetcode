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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head, *slow=head, *tmp;
        for(int i=0;i<n;i++) {
            fast=fast->next;
        }
        
        if (fast==nullptr) {
            tmp=head;
            head=head->next;
            delete tmp;
            return head;
        }
        while(fast->next) {
            fast=fast->next;
            slow=slow->next;
        }
        tmp=slow->next;
        slow->next=slow->next->next;
        delete tmp;
        return head;   
    }
};