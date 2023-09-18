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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
        {
            return head;
        }

        ListNode* headOdd{};
        ListNode* headEven{};
        ListNode* modifier{};
        if (head->next == nullptr || head->next->next == nullptr)
        {
            return head;
        }

        headOdd = head;
        headEven = head->next;
        modifier = head;
        head = head->next;
        
        size_t index = 0;
        while (head->next != nullptr)
        {
            modifier->next = head->next;
            modifier = head;
            head = head->next;
            ++index;
        }

        if (index % 2 == 0)
        {
            modifier->next = headEven;
        }
        else
        {
            modifier->next = nullptr;
            head->next = headEven;
        }

        return headOdd;
    }
};