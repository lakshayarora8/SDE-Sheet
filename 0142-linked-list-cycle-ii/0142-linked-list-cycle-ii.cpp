class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow=head,*fast=head;
         if(head==NULL||head->next==NULL||!head->next->next)
            return NULL;
        while(fast->next !=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast)
                break;
        }
        if(slow != fast)
        return NULL;
        fast=head;

        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};