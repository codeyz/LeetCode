/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// note: it's about the node number(or index) while not the values in nodes
// break the list into two parts, one includes the odd-indexed nodes and and the other includes the even-indexed nodex
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        ListNode* oddTail = head;
        ListNode* evenTail = head->next;
        ListNode* evenHead = head->next;
        ListNode* p = head->next->next;
        int i = 3;
        while(p)
        {
            if(i % 2)  // odd index
            {
                oddTail = oddTail->next = p;
            }
            else    // even index
            {
                evenTail = evenTail->next = p;
            }
            p = p->next;
            ++i;
        }
        oddTail->next = evenHead;
        evenTail->next = NULL;
        return head;
    }
};
