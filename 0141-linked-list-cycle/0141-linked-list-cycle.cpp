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
    bool hasCycle(ListNode *head) {

        if(head==nullptr || head->next==nullptr) return false;
        ListNode* current1=head;
        ListNode* current2=head;
        
        while(current1!=nullptr && current1->next!=nullptr)
        {
           
            current1=current1->next->next;
            current2=current2->next;
            if(current1!=nullptr && current2!=nullptr)
            {
                if(current1==current2) return true;
            }
            else return false;
        }
        return false;
    }
};