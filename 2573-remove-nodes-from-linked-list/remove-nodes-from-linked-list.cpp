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
        ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next=nullptr;
        while(curr) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newHead=reverse(head);
        ListNode* curr=newHead->next;
        ListNode* curr1=newHead;
        int max=newHead->val;
        while(curr) {
            if(curr->val>=max){
                ListNode *tmp=curr->next;
                curr1->next=curr;
                curr1 =curr1->next;
                max=curr->val;
                curr =curr->next;
            } else {
                ListNode *tmp=curr;
                curr=curr->next;
                //delete tmp;
            }
            //curr =curr->next;
        }
        curr1->next=nullptr;
        return reverse(newHead);
    }
};