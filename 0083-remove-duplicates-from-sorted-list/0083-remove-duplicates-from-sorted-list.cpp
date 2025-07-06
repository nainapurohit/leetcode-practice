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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* curr=head;
        ListNode* ahead=head->next;
        while (ahead!=nullptr){
            if (curr->val==ahead->val) {
                ahead=ahead->next;
                curr->next=ahead;
                continue;
            }
            ahead=ahead->next;
            curr=curr->next;
        }
        return head;
    }
};