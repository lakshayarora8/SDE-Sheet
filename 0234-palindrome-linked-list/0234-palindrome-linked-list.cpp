class Solution {
public:

    ListNode* reverse(ListNode* head)
    {

        if(head == NULL || head->next == NULL)
        return head;

        ListNode *prev=NULL,*curr=head,*next=head;
        while(curr != NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next ==NULL)
        return true;
      
        ListNode* slow=head,*fast=head;

        while( fast->next!=NULL && fast->next->next!=NULL )
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        while(slow != NULL)
        {
            if(slow->val != head->val)
            return false;

            slow=slow->next;
            head=head->next;
        }
        return true;
        
    }
};