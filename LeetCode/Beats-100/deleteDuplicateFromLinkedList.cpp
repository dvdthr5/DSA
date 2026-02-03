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
        if (head == NULL){
            return NULL;
        }
        ListNode* firstOccur = head;
        ListNode* current = head->next;
        while (current != NULL){
            if (firstOccur->val == current->val){
                ListNode* temp = current;
                current = temp->next;
                firstOccur->next = current;
                temp->next = NULL;
            }
            else{
                firstOccur = firstOccur->next;
                current = current->next;
            }
        }
        return head;
    }
};
