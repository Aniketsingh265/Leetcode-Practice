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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL or head->next ==NULL){
            return head;
        }
        ListNode* dummy  = new ListNode();
        ListNode* curr = head;
        while(curr != NULL){
            //find the curr position 
            ListNode* ptr = dummy;
            while(ptr->next != NULL and ptr->next->val <= curr->val){
                ptr = ptr->next;
            }
            //now fir curr node after ptr
            ListNode* temp = curr->next;
            curr->next = ptr->next;
            ptr->next = curr;
            curr = temp;
        }
        return dummy->next;
    }
};