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
    ListNode* oddEvenList(ListNode* head) {
        
        int cnt=0;
        ListNode* dummy=head;
        while(dummy!=nullptr)
        {
            cnt++;
            dummy=dummy->next;
        }

        int n=(cnt-1)/2;
        
        ListNode* base=head;
        while(n)
        {
            ListNode* temp=base->next;
            int p=n;
            ListNode* l=base;
            while(p)
            {
                ListNode* k=temp->next;
                temp->next=k->next;
                l->next=k;
                k->next=temp;
                l=temp;
                temp=temp->next;
                p--;
            }
            base=base->next;
            n--;
        }
        return head;
    }
};