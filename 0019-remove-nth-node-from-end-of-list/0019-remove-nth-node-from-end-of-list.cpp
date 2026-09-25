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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL)
        {
            return head;
        }

        int length = 0;

        ListNode * temp = head;
        while(temp != NULL)
        {
            temp = temp -> next;
            length++;
        }

        int ans_count = length - n + 1;

        temp = head;
        ListNode *prev = nullptr;

        if(ans_count == 1)
        {
            ListNode *temp = head;
            head = head -> next;
            delete temp;
            return head;
        }

        int count = 0;
        while(temp != nullptr)
        {
            count ++;
            if(count == ans_count)
            {
                prev -> next = prev->next->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp -> next;
        }
        return head;
    }
};