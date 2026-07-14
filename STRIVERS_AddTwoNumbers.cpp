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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while (head1 != NULL or head2 != NULL or carry != 0) {
            int sum = 0;
            if (head1 != NULL) {
                sum += head1->val;
                head1 = head1->next;
            }
            if (head2 != NULL) {
                sum += head2->val;
                head2 = head2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};
