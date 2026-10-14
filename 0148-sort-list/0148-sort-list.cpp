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
    ListNode* middleNode(ListNode* head) {
        ListNode * fast = head -> next;
        ListNode * slow = head;

        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode * merge2(ListNode * list1, ListNode * list2)
    {
        ListNode * dummynode = new ListNode(-1);
        ListNode * temp = dummynode;

        while(list1 != NULL && list2 != NULL)
        {
            if(list1 -> val < list2 -> val)
            {
                temp -> next = list1;
                temp = list1;
                list1 = list1 -> next;
            }
            else
            {
                temp -> next = list2;
                temp = list2;
                list2 = list2 -> next;
            }
        }

        if(list1) temp -> next = list1;
        else temp -> next = list2;

        return dummynode -> next;
    }

    ListNode* sortList(ListNode* head) {

        if(head == NULL || head -> next == NULL)
        {
            return head;
        }

        ListNode * middle = middleNode(head);
        ListNode * left_part = head;
        ListNode * right_part = middle -> next;
        middle -> next = NULL;

        left_part = sortList(left_part);
        right_part = sortList(right_part);

        return merge2(left_part, right_part);
    }
};