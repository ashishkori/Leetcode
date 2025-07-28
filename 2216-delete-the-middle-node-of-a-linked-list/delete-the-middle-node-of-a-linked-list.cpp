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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev;
        if(!head->next) return nullptr;
        //if(head==nullptr) return false;
        while(fast && fast->next) {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next; 
        }
        //ListNode *tmp=slow;
        if(prev) prev->next=slow->next;
        else delete slow;
        //delete tmp;
        return head;
    }
};