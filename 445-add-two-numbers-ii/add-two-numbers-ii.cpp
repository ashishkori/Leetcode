
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode*curr=head;
        ListNode* prev=nullptr;
        ListNode* next=nullptr;
        while(curr) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1=reverse(l1);
        ListNode* list2=reverse(l2);

        int carry=0;
        ListNode* head=nullptr;
        while(list1 || list2 || carry) {
            int n1=0, n2=0;
            if(list1) {
                n1=list1->val;
                list1=list1->next;
            }
            if(list2) {
                n2=list2->val;
                list2=list2->next;
            }
            int s=n1+n2+carry;
            carry=s/10;
            s=s%10;
            ListNode* tmp=new ListNode(s);
            if(!head) head=tmp;
            else {
                tmp->next=head;
                head=tmp;
            }
        }
        return head;
    }
};