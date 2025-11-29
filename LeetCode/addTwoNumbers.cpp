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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* counter = l1;
        ListNode* counter2 = l2;
        ListNode* head = NULL;
        ListNode* lastNode = NULL;
        int carry = 0;
        while (counter != NULL || counter2 != NULL || carry != 0){

            int valu1=0, valu2=0;
            if (counter != NULL){
                valu1 = counter->val;
                counter = counter->next;
            }
            if (counter2 != NULL){
                valu2 = counter2->val;
                counter2 = counter2->next;
            }
            int tempsum = valu1 + valu2 + carry;
            int sum = 0;
            if (tempsum- 10 >=0){
            sum = tempsum - 10;
            carry = 1;
            }
            else{
                sum = tempsum;
                carry = 0;
            }
            ListNode *temp = new ListNode(sum);
            if (lastNode == NULL){
                head = temp;
                lastNode = head;
            }
            else{
                lastNode->next = temp;
                lastNode = temp;
            }
        }
        return head;
    }
}; 
