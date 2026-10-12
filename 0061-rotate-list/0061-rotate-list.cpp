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
    ListNode * find_nth_node(ListNode * temp, int k)
    {
        int count = 1;
        while(temp != NULL)
        {
            if(count == k) return temp;
            count++;
            temp = temp -> next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head -> next == NULL) return head;
        
        int len = 1;
        ListNode * tail = head;

        while(tail -> next != NULL)
        {
            len++;
            tail = tail -> next;
        }

        if(k % len == 0) return head;

        k = k % len;

        tail -> next = head;

        ListNode * newlastnode = find_nth_node(head, len - k);

        head = newlastnode -> next;
        newlastnode -> next = NULL;

        return head;


    }
};