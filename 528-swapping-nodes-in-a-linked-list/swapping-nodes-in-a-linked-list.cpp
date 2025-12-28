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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head) return head;
        ListNode* curr=head;
        ListNode* p1=nullptr;
        ListNode* p2=nullptr;
        // while(--k) {
        //     curr=curr->next;
        // }
        // p1=curr;
        // p2=head;
        while(curr) { 
            if(p2) p2=p2->next;
            k--;
            if (k==0) {
                p1=curr;
                p2=head;
            }
            curr=curr->next;
        }
        cout<<p1->val << " " <<p2->val;
        swap(p1->val,p2->val);
        return head;

    }
};