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
    ListNode* collosion(ListNode* temp1, ListNode* temp2, int d)
    {
        while(d)
        {
            d--;
            temp2 = temp2 -> next; 
        }
        while(temp1 != temp2)
        {
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return temp1;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0;
        int n2 = 0;

        ListNode * temp1 = headA;
        ListNode * temp2 = headB;

        while(temp1 != NULL)
        {
            n1++;
            temp1 = temp1 -> next;
        }

        while(temp2 != NULL)
        {
            n2++;
            temp2 = temp2 ->next;
        }

        if(n1 < n2)
        {
            return collosion(headA,headB,n2 - n1);
        }
        else
        {
            return collosion(headB,headA,n1 - n2);
        }
    }
};