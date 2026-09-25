/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode * temp1 = list1;
        ListNode * temp2 = list2;

        ListNode * dummynode = new ListNode(-1);
        ListNode * current = dummynode;
        
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1 -> val <= temp2 -> val)
            {
                current -> next = temp1;
                temp1 = temp1 -> next;
            }
            else
            {
                current -> next = temp2;
                temp2 = temp2 -> next;
            }

            current = current -> next;
        }

        while(temp1 != NULL)
        {
            current -> next = temp1;
            temp1 = temp1 -> next;
            current = current -> next;
        }

        while(temp2 != NULL)
        {
            current -> next = temp2;
            temp2 = temp2 -> next;
            current = current -> next;
        }

        return dummynode -> next;
    }
};