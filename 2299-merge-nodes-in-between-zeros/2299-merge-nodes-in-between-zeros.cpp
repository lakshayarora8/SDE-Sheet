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

        ListNode* ans=head->next;
        int sum=0;
        head=head->next;
        ListNode * temp=head;
        while(temp != NULL)
        {
            if(temp->val != 0)
            {
                sum+=temp->val;
                // temp=temp->next;
            }
            else
            {
                head->val=sum;
                head->next=temp->next;
                head=head->next;
                sum=0;
            }
            temp=temp->next;
        }
        return ans;
    }
};