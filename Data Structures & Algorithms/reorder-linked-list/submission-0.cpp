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

        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while(mid != nullptr){
            ListNode* next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }

        ListNode* final = head;
        while(prev != nullptr){

            ListNode* next1 = final->next;
            ListNode* next2 = prev->next;

            final->next = prev;
            prev->next = next1;

            final = next1;
            prev = next2;
        }

        
    }
};
