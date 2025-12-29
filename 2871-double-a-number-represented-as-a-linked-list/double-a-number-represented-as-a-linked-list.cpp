
class Solution {
public:
        ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        if(!head) return head;
        ListNode* rev=reverse(head);
        int carry=0;
        ListNode* curr=rev;
        ListNode* prv=nullptr;
        while(curr) {
            int val=curr->val*2+carry;
            carry=val/10;
            curr->val=val%10;
            prv=curr;
            curr=curr->next;
        }
        if(carry) {
            prv->next=new ListNode(carry);
        }
        return reverse(rev);
    }
};