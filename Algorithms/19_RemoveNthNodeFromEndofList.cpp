/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *p, *q, *prev;
        prev = p = q = head;
        while(n-- && p)
            p = p->next;
        // invalid n
        if(n >= 0)
            return head;
        while(p)
        {
            p = p->next;
            prev = q;
            q = q->next;
        }
        // delete q
        if(q == head)
        {
            head = head->next;
            free(q);
        }
        else
        {
            prev->next = q->next;
            free(q);
        }
        return head;
    }
};
