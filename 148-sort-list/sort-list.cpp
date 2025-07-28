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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* tmp, *dummy;
        dummy = new ListNode(-1);
        tmp=dummy;
        if(!list1 && !list2) return NULL;
        while(list1&&list2) {
            if(list1->val < list2->val) {
                tmp->next=list1;
                tmp=tmp->next;
                list1=list1->next;
            } else {
                tmp->next=list2;
                tmp=tmp->next;
                list2=list2->next;
            }
        }
        if(list1) tmp->next=list1;
        if(list2) tmp->next=list2;
        return dummy->next;
    }
    ListNode* findMid(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast &&fast->next) {
            fast=fast->next->next;
            slow=slow->next;
        }  
        return slow;
    }
    ListNode* mSort(ListNode* head) {
        ListNode *mid, *left, *right;
        if(!head || !head->next) return head;
        mid = findMid(head);
        left = head;
        right = mid->next;
        mid->next=NULL;
        left = mSort(left);
        right = mSort(right);
        return merge(left,right);

    }
    ListNode* sortList(ListNode* head) {
        return mSort(head);
    }
};