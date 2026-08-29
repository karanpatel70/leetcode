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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            head = head->next;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL) {
            if (prev == NULL && curr->val == val) {
                prev = curr;
                curr = curr->next;
                continue;
            } else if (prev != NULL && curr->val == val) {
                curr = curr->next;
                prev->next = curr;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};