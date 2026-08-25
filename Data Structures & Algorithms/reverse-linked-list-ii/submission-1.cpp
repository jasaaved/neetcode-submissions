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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy;
        dummy.next = head;

        ListNode* before = &dummy;

        for(int i = 1; i < left; ++i){
            before = before->next;
        }

        ListNode* curr = before->next;
        ListNode* prev;

        for(int i = left; i <= right; ++i){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        before->next->next = curr;
        before->next = prev;
        
        return dummy.next;
    }
};