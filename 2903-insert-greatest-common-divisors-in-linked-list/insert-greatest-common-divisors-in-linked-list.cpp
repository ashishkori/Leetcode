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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head;

        while(curr->next) {
            ListNode* nextNode=curr->next;
            curr->next=new ListNode(__gcd(curr->val,nextNode->val));
            curr->next->next=nextNode;
            curr=nextNode;
        }
        return head;
    }
};