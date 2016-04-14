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
    bool isPalindrome(ListNode* head) 
    {
        int length = getLength(head);
        if(length <= 1)
            return true;
        // divide into two lists
        ListNode *p1, *p2, *middle;
        p1 = p2 = head;
        for(int i = 0;i < length / 2 - 1; ++i)
            p2 = p2->next;
        middle = p2;
        p2 = p2->next;
        middle->next = NULL;
        
        //reverse the second list
        p2 = reverse(p2);
        bool flag = isSame(p1, p2);
        // reverse back
        p2 = reverse(p2);
        middle->next = p2;
        return flag;
    }
    
    bool isSame(ListNode* head1, ListNode* head2)
    {
        ListNode *h1 = head1, *h2 = head2;
        while(h1 && h2)
        {
            if(h1->val != h2->val)
                return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head)
    {
        if(!head)
            return head;
        ListNode* p = head->next;
        head->next = NULL;
        while(p)
        {
            ListNode* tmp = p->next;
            p->next = head;
            head = p;
            p = tmp;
        }
        return head;
    }
    
    int getLength(ListNode* head)
    {
        int length = 0;
        for(ListNode* tmp = head; tmp; tmp = tmp->next)
            ++length;
        return length;
    }
};
