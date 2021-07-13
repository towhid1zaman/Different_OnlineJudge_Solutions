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
        if(head == NULL)return head;
        ListNode *first = head;
        while(first and first->next){
            ListNode *second = first->next;
            if(first->val == second->val){
                first->next = second->next;
            }
            else first = second;
        }
        return head;
    }
};
