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
    bool fun(ListNode* head)
    {
        ListNode* current1=head;
        ListNode* current2=head;

        while(current1!=nullptr && current1->next!=nullptr)
        {
            current1=current1->next->next;
            current2=current2->next;
            if(current1==current2) return true;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        
        if(head==nullptr || head->next==nullptr) return NULL;

        bool isok=fun(head);
        if(isok)
        {
            set<ListNode*> st;
            ListNode* dummy=head;
            while(!st.count(dummy))
            {
                st.insert(dummy);
                dummy=dummy->next;
            }
            return dummy;
        }
        return NULL;
    }
};