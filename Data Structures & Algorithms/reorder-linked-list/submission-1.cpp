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

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* mid = reverse(slow->next);
        slow->next = nullptr;
        ListNode* final = head;

        while(mid != nullptr) {
            ListNode* next1 = final->next;
            ListNode* next2 = mid->next;

            final->next = mid;
            mid->next = next1;

            final = next1;
            mid = next2;
        }
    }

private:
    ListNode* reverse(ListNode* head){
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
