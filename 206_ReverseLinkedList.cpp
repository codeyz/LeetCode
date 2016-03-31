/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/* non-recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head)
            return head;
        ListNode* prev = head->next;
        head->next = NULL;
        while(prev)
        {
            ListNode* tmp = prev->next;
            prev->next = head;
            head = prev;
            prev = tmp;
        }
        return head;
    }
};
*/

// recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        reverseList(head, NULL);
    }
    
    ListNode* reverseList(ListNode* head, ListNode* prev)
    {
        if(!head || !head->next)
            return head;
        ListNode* next = head->next;
        ListNode* newHead = reverseList(next, head);
        head->next = prev;
        next->next = head;
        return newHead;
    }
};
