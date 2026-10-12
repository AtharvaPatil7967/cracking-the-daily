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
    ListNode * reverse_linked_list(ListNode * temp)
    {
        ListNode * curr = temp;
        ListNode * prev = NULL;

        while(curr != NULL)
        {
            ListNode * front = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    ListNode* get_kth_node(ListNode * temp, int k)
    {
        k-=1;
        while(temp != NULL && k>0)
        {
            k--;
            temp = temp -> next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode * temp = head;
        ListNode * prevlast = NULL;

        while(temp != NULL)
        {
            ListNode * kthNode = get_kth_node(temp, k);
            if(kthNode == NULL)
            {
                if(prevlast) prevlast -> next = temp;
                break;
            }

            ListNode * nextnode = kthNode -> next;
            kthNode -> next = NULL;

            reverse_linked_list(temp);

            if(temp == head)
            {
                head = kthNode;
            }
            else
            {
                prevlast -> next = kthNode;
            }

            prevlast = temp;
            temp = nextnode;
        }
        return head;
    }
};