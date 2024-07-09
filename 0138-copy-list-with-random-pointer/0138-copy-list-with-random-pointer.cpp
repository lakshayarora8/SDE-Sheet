/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL)
        return NULL;
        
        Node *clone=new Node(head->val);
        Node* clonehead=clone;
        unordered_map<Node*,Node*> mp;
        mp[head]=clone;
        mp[NULL]=NULL;
        while(head != NULL)
        {
            if(mp.find(head->random) == mp.end())
            {
                Node* clone_random=new Node(head->random->val);
                mp[head->random]=clone_random;
                clone->random=clone_random;
            }
            else    
            {
                clone->random=mp[head->random];
            }

            if(mp.find(head->next) == mp.end())
            {
                Node* clone_next=new Node(head->next->val);
                mp[head->next]=clone_next;
                clone->next=clone_next;
            }
            else    
            {
                clone->next=mp[head->next];
            }
            clone=clone->next;
            head=head->next;
        }

        return clonehead;
    }
};