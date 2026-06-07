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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==nullptr) return head;
        ListNode* check=head;
        int cnt=0;
        while(check)
        {
            cnt++;
            check=check->next;
        }

        k=k%cnt;
        if(k==0) return head;
        ListNode* current=head;

        while(current->next!=nullptr)
        {
            current=current->next;
        }
        current->next=head;

        int mov=cnt-k;
        current=head;
        mov--;
        while(mov)
        {
            current=current->next;
            mov--;
        }
        head=current->next;
        current->next=nullptr;
        return head;

    }
};