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
    bool hasCycle(ListNode *head) 
    {
        if(!head)
            return 0;
        ListNode *p1, *p2;
        p1 = head->next;
        if(!p1 || !p1->next)
            return 0;
        p2 = p1->next;
        while(p1 && p2 && p1 != p2)
        {
            p1 = p1->next;
            if(!p1 || !p1->next)
                return 0;
            if(!p2->next || !p2->next->next)
                return 0;
            p2 = p2->next->next;
        }
        return p1 == p2;
    }
};
