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
    ListNode* rotateRight(ListNode* head, int k) {

        vector<int> vec;
        ListNode *temp=head;
        if(head == NULL)
        return NULL;
        while(temp!=NULL)
        {
            vec.push_back(temp->val);
            temp=temp->next;
        }
        int n=vec.size();
        long long rotations=k%n;
        rotate(vec.begin(), vec.begin() + (n-rotations), vec.end());
        temp=head;
        int i=0;
        while(temp!=NULL)
        {
            temp->val=vec[i++];
            temp=temp->next;
        }
        return head;
    }
};