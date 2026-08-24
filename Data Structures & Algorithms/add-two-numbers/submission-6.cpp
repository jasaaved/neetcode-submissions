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

        int carry = 0;

        while(l1 != nullptr && l2 != nullptr){
            carry = add(carry, l1, l2);
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 == nullptr){
            prev->next = l2;
        }

        while(carry > 0){
            if(prev->next == nullptr){
                prev->next = new ListNode();
            }

            prev = prev->next;
            carry = add(carry, prev);
        }

        return head;
    }

private:
    int add(int carry, ListNode* l1, ListNode* l2 = nullptr){
        int l2_val = l2 == nullptr ? 0 : l2->val;

        int sum = l1->val + l2_val + carry;
        l1->val = sum % 10;

        return sum / 10;
    }
};
