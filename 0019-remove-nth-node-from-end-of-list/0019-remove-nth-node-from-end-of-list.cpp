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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL || head->next==NULL)
            return NULL;
        int length=0;
        
        ListNode * temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            length++;
        }
        
        if(n == length)
        {
            head=head->next;
            return head;
        }
        
        length-=n+1;
        
        temp=head;
        while(length>0)
        {
            length--;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
        
    }
};