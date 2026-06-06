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

        ListNode* dummy=new ListNode(0);
        ListNode* current=dummy;

        int carry=0;

        while(l1 && l2)
        {
            int a=carry+l1->val+l2->val;

            carry=a/10;

            int n=a%10;
            current->val=n;
            ListNode* newNode=new ListNode(0);
            if(l1->next!=nullptr && l2->next!=nullptr){

                current->next=newNode;
                current=current->next;
            }
            //else break;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            int a=carry+l1->val;

            carry=a/10;

            int n=a%10;
            ListNode* newNode=new ListNode(0);
            current->next=newNode;
            current=current->next;
            current->val=n;
            
            
            l1=l1->next;
        }
        while(l2)
        {
            int a=carry+l2->val;

            carry=a/10;

            int n=a%10;
            ListNode* newNode=new ListNode(0);
            current->next=newNode;
            current=current->next;
            current->val=n;

            
            l2=l2->next;
        }
        if(carry!=0)
        {
            ListNode* newNode=new ListNode(carry);
            current->next=newNode;
            current=current->next;
        }
        return dummy;

    }
};