class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //Tortoise & Hare Method.
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
