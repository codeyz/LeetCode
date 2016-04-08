/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(!headA || !headB)
            return NULL;
        // reverse list A
        ListNode* newHead = reverseLinkedList(headA);
        ListNode* tmp = headB;
        while(tmp->next)
        {
            tmp = tmp->next;
        }
        if(tmp != headA)
        {
            reverseLinkedList(newHead);
            return NULL;
        }
        int countOfA, countOfB, countOfnotShared;
        countOfnotShared = getCount(headB);
        // reverse list A
        reverseLinkedList(newHead);
        countOfA = getCount(headA);
        countOfB = getCount(headB);
        
        countOfA = (countOfnotShared + countOfA - countOfB) / 2;
        
        tmp = headA;
        while(countOfA--)
            tmp = tmp->next;
        return tmp;
    }
    
    ListNode* reverseLinkedList(ListNode* head)
    {
        if(!head)
            return NULL;
        ListNode *newHead = head, *next = head->next;
        head->next = NULL;
        while(next)
        {
            ListNode* tmp = next->next;
            next->next = newHead;
            newHead = next;
            next = tmp;
        }
        return newHead;
    }
    
    int getCount(ListNode* head)
    {
        int count = 0;
        ListNode* p = head;
        while(p)
        {
            ++count;
            p = p->next;
        }
        return count;
    }
};
*/

/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int lengthOfA, lengthOfB;
        lengthOfA = getLength(headA);
        lengthOfB = getLength(headB);
        if(!lengthOfA || !lengthOfB)
            return NULL;
        ListNode *pa, *pb;
        pa = headA, pb = headB;
        if(lengthOfA <= lengthOfB)
        {
            for(int i = 0;i < lengthOfB - lengthOfA; ++i)
                pb = pb->next;
        }
        else
        {
            for(int i = 0;i < lengthOfA - lengthOfB; ++i)
                pa = pa->next;
        }
        while(pa != pb)
        {
            pa = pa->next;
            pb = pb->next;
        }
        return pa;
    }
    
    int getLength(ListNode* head)
    {
        int count = 0;
        ListNode* p = head;
        while(p)
        {
            ++count;
            p = p->next;
        }
        return count;
    }
};
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        bool flagA, flagB;
        flagA = flagB = false;
        ListNode *pa = headA, *pb = headB;
        while(pa && pb)
        {
            if(!pa->next || !pb->next)
            {
                if(!pa->next && !flagA)
                {
                    pa = headB;
                    flagA = true;
                }
                if(!pb->next && !flagB)
                {
                    pb = headA;
                    flagB = true;
                }
                if(flagA && flagB)
                    break;
            }
            else
            {
                pa = pa->next;
                pb = pb->next;
            }
        }
        while(pa && pb && pa != pb)
        {
            pa = pa->next;
            pb = pb->next;
        }
        return pa == pb ? pa : NULL;
    }
};

