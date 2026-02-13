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
        if (head == NULL){
            return NULL;
        }
        ListNode* current = head;
        ListNode* prev = NULL;
        while (current != NULL){
            if (current->val == val){
                if (current == head){
                    prev = current;
                    current = current->next;
                    head = current;
                    prev->next = NULL;
                }
                else{
                    prev->next = current->next;
                    current->next = NULL;
                    current = prev->next;
                }
            } else{
                prev = current;
            current = current->next;
            }
            
        }
        return head;
    }
};
