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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* prev = nullptr;

        int remainder = 0;

        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val + remainder;
            l1->val = sum % 10;
            remainder = sum / 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 == nullptr){
            prev->next = l2;
        }

        while(remainder > 0){
            if(prev->next == nullptr){
                prev->next = new ListNode();
            }

            prev = prev->next;
            int sum = prev->val + remainder;
            prev->val = sum % 10;
            remainder = sum / 10;
        }

        return head;
    }
};
