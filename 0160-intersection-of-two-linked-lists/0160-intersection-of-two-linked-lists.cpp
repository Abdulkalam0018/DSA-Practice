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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int cnt1=0;
        int cnt2=0;

        ListNode* dummy1=headA;
        ListNode* dummy2=headB;

        while(dummy1!=nullptr)
        {
            dummy1=dummy1->next;
            cnt1++;
        }
        while(dummy2!=nullptr)
        {
            dummy2=dummy2->next;
            cnt2++;
        }

        if(cnt1>=cnt2)
        {
            int a=cnt1-cnt2;
            dummy1=headA;

            while(a)
            {
                dummy1=dummy1->next;
                a--;
            }
            dummy2=headB;
            
            while(dummy1!=dummy2)
            {
                dummy1=dummy1->next;
                dummy2=dummy2->next;
            }
            return dummy1;
        }   
        else
        {
            int a=abs(cnt1-cnt2);
            dummy1=headA;
            dummy2=headB;
            while(a)
            {
                dummy2=dummy2->next;
                a--;
            }
            
            
            while(dummy1!=dummy2)
            {
                dummy1=dummy1->next;
                dummy2=dummy2->next;
            }
            return dummy1;
        }
        return nullptr;


    }
};