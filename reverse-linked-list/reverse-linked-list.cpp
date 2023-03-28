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
        if(head == nullptr)
        {
            return head;
        }

        ListNode* prevIt = head;
        if(head->next == nullptr)
        {
            return head;
        }

        ListNode* it = head->next;
        prevIt->next = nullptr;
        if(it->next == nullptr)
        {
            it->next = prevIt;
            return it;
        }

        ListNode* nextIt = nullptr;
        while(true)
        {
            nextIt = it->next;
            if(nextIt == nullptr)
            {
                it->next = prevIt;
                break;
            }

            it->next = prevIt;
            prevIt = it;
            it = nextIt;
        }

        return it;
    }
};