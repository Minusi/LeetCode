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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result{};
        if(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                result = list1;
                list1 = list1->next;
                result->next = nullptr;
            }
            else
            {
                result = list2;
                list2 = list2->next;
                result->next = nullptr;
            }
        }
        else if(list1)
        {
            result = list1;
            return result;
        }
        else if(list2)
        {
            result = list2;
            return result;
        }
        else
        {
            return result;
        }

        ListNode* resIt = result;
        while(true)
        {
            if(list1 && list2)
            {
                if(list1->val <= list2->val)
                {
                    resIt->next = list1;
                    list1 = list1->next;
                    resIt = resIt->next;
                    resIt->next = nullptr;
                }
                else
                {
                    resIt->next = list2;
                    list2 = list2->next;
                    resIt = resIt->next;
                    resIt->next = nullptr;
                }
            }
            else if(list1)
            {
                resIt->next= list1;
                break;
            }
            else if(list2)
            {
                resIt->next = list2;
                break;
            }
            else
            {
                break;
            }
        }

        return result;
    }
};