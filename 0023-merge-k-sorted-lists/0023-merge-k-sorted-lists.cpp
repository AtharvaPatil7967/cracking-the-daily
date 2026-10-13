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
    ListNode * covert (vector<int>& arr)
    {
        if(arr.size() == 0) return NULL;

        ListNode * head = new ListNode(arr[0]);
        ListNode * temp = head;

        for(int i=1; i<arr.size(); i++)
        {
            ListNode * newNode = new ListNode(arr[i]);
            temp -> next = newNode;
            temp = temp -> next;
        }
        temp -> next = NULL;
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n = lists.size();
        vector<int> arr;

        for(int i=0; i<n; i++)
        {
            ListNode * temp = lists[i];

            while(temp != NULL)
            {
                arr.push_back(temp -> val);
                temp = temp -> next;
            }
        }
        
        sort(arr.begin(), arr.end());

        ListNode * head = covert(arr);

        return head;

    }
};