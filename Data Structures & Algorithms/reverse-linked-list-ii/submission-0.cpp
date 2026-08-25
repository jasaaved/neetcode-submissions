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

        ListNode* reverse_list = &dummy;
        int count = 0;

        ListNode* prev;
        ListNode* after;

        ListNode* left_node;
        ListNode* n_head;

        while(count <= right){
            ++count;

            if(count == left){
                prev = reverse_list;
                left_node = reverse_list->next;
            }

            else if(count == right + 1){
                after = reverse_list->next;
                reverse_list->next = nullptr;
                n_head = reverse(left_node);
            }

            reverse_list = reverse_list->next;
        }

        prev->next = n_head;
        left_node->next = after;
        
        return dummy.next;
    }

private:

    ListNode* reverse(ListNode* a) {
        ListNode* prev = nullptr;

        while(a != nullptr){
            ListNode* next = a->next;
            a->next = prev;
            prev = a;
            a = next;
        }

        return prev;
    }
};