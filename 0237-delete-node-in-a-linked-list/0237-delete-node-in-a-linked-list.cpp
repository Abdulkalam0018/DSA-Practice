/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* dummy=node;

        while(dummy->next->next!=nullptr)
        {
            int data=dummy->next->val;
            dummy->val=data;
            dummy=dummy->next;
        }
        dummy->val=dummy->next->val;
        delete dummy->next;
        dummy->next=nullptr;
    }
};