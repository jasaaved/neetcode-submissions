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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = reverse(slow->next);
        slow->next = nullptr;

        while(second != nullptr){
            ListNode* next1 = head->next;
            ListNode* next2 = second->next;

            head->next = second;
            second->next = next1;

            head = next1;
            second = next2;
        }
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;

        while(head != nullptr){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};
