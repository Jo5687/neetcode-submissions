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
    ListNode* reverseList(ListNode* head) {
        //End of list
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        //Go down list for new head
        ListNode* reverseHead = reverseList(head->next);
        //Flip
        head->next->next = head;
        //Break old edge
        head->next = nullptr;
        //Return fixed node
        return reverseHead;
    }
};
