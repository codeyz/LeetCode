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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1 && l2)
        {
            ListNode *head, *head1, *head2, *tail;
            if(l1->val <= l2->val)
            {
                head = tail = l1;
                head1 = l1->next;
                head2 = l2;
            }
            else
            {
                head = tail = l2;
                head1 = l1;
                head2 = l2->next;
            }
            while(head1 && head2)
            {
                if(head1->val <= head2->val)
                {
                    tail->next = head1;
                    head1 = head1->next;
                }
                else
                {
                    tail->next = head2;
                    head2 = head2->next;
                }
                tail = tail->next;
            }
            if(head1)
                tail->next = head1;
            else
                tail->next = head2;
            return head;
        }
        return l1 ? l1 : l2;
        
    }
};
