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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *prev, *next;
        prev = next = head;
        while(next)
        {
            if(next->val == val)
            {
                if(next == head)
                {
                    prev = head->next;
                    free(head);
                    head = prev;
                }
                else
                {
                    prev->next = next->next;
                    next = prev->next;
                }
            }
            else
            {
                prev = next;
                next = next->next;
            }
        }
        return head;
    }
};
