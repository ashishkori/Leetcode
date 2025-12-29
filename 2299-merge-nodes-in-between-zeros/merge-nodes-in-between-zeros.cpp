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
    ListNode* mergeNodes(ListNode* head) {
        head= head->next;
        if(!head) return head;
        ListNode* tmp=head;
        int sum=0;
        while(tmp && tmp->val !=0) {
            sum+=tmp->val;
            tmp=tmp->next;
        }
        head->val=sum;
        head->next=mergeNodes(tmp);
        return head;
    }
};