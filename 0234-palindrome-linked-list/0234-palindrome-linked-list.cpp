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
        if(head->next->next == NULL)
        {
            if(head->val == head->next->val)
            return true;
            return false;
        }
      
    
        ListNode* slow=head,*fast=head;

        while( fast->next!=NULL && fast->next->next!=NULL )
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* dummy=reverse(slow->next);
        slow->next=dummy;

        while(dummy != NULL)
        {
            if(dummy->val != head->val)
            return false;

            dummy=dummy->next;
            head=head->next;
        }
        return true;
        
    }
};