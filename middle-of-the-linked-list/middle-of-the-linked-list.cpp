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
        ListNode* nodeIndex = head;

        auto index = 0;
        while(head != nullptr)
        {
            ++index;
            if(index % 2 == 0)
            {
                nodeIndex = nodeIndex->next;
            }
            
            head = head->next;
        }

        return nodeIndex;
    }
};