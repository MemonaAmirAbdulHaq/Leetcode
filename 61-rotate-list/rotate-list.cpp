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
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the list
        ListNode* curr = head;
        int length = 1;
        while (curr->next) {
            curr = curr->next;
            length++;
        }

        // Step 2: Connect the last node to head to form a circle
        curr->next = head;

        // Step 3: Find the new tail: (length - k % length - 1)th node
        // and the new head: (length - k % length)th node
        k %= length;
        int stepsToNewHead = length - k;
        ListNode* newTail = curr;
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};