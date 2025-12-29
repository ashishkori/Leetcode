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
    ListNode* insertGreatestCommonDivisors1(ListNode* head) {
        ListNode* curr=head;
        while(curr->next) {
            ListNode* nextNode=curr->next;
            curr->next=new ListNode(__gcd(curr->val,nextNode->val));
            curr->next->next=nextNode;
            curr=nextNode;
        }
        return head;
    }
    ListNode* insertGreatestCommonDivisorsRec(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* node=new ListNode(__gcd(head->val,head->next->val));
        ListNode *prev=insertGreatestCommonDivisorsRec(head->next);
        head->next=node;
        head->next->next=prev;
        return head;
    };

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        return 1?insertGreatestCommonDivisors1(head):insertGreatestCommonDivisorsRec(head);
    }
};